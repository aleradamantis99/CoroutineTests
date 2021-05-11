#pragma once

#include <atomic>
#include <cppcoro/coroutine.hpp>

namespace asyncio
{
	class single_thread_event
	{
	public:

		single_thread_event(bool initiallySet = false) noexcept
			: m_state(initiallySet ? state::set : state::not_set)
		{}

		/// Query if this event has been set.
		bool is_set() const noexcept
		{
			return m_state == state::set;
		}

		void set()
		{
			const state oldState = m_state;
			m_state = state::set;
			if (oldState == state::not_set_consumer_waiting)
			{
				m_awaiter.resume();
			}
		}

		/// \brief
		/// Transition this event to the 'non set' state if it was in the set state.
		void reset() noexcept
		{
			if (m_state == state::set)
			{
				m_state = state::not_set;
			}
		}

		/// \brief
		/// Wait until the event becomes set.
		///
		/// If the event is already set then the awaiting coroutine will not be suspended
		/// and will continue execution. If the event was not yet set then the coroutine
		/// will be suspended and will be later resumed inside a subsequent call to set()
		/// on the thread that calls set().
		auto operator co_await() noexcept
		{
			class awaiter
			{
			public:

				awaiter(single_thread_event& event) : m_event(event) {}

				bool await_ready() const noexcept
				{
					return m_event.is_set();
				}

				bool await_suspend(cppcoro::coroutine_handle<> awaiter)
				{
					m_event.m_awaiter = awaiter;
					if (m_event.m_state == state::not_set)
					{
						m_event.m_state = state::not_set_consumer_waiting;
						return true;
					}
					return false;
				}

				void await_resume() noexcept {}

			private:

				single_thread_event& m_event;

			};

			return awaiter{ *this };
		}

	private:

		enum class state
		{
			not_set,
			not_set_consumer_waiting,
			set
		};

		// TODO: Merge these two fields into a single std::atomic<std::uintptr_t>
		// by encoding 'not_set' as 0 (nullptr), 'set' as 1 and
		// 'not_set_consumer_waiting' as a coroutine handle pointer.
		state m_state;
		cppcoro::coroutine_handle<> m_awaiter;

	};
}
