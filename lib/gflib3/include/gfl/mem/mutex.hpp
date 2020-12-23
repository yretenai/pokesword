#pragma once

#include <nn/types.h>
#include <nn/os.h>
#include <gfl/macros.h>

// not sure if this is how it's done
namespace gfl::mem {
    class LOCKABLE Mutex {
    GFL_DELETE_COPY_CONSTRUCTOR(Mutex);

    private:
        nn::os::MutexType GUARDED_VAR(mutex_lock);
    public:
        Mutex() noexcept = default;

        ~Mutex() noexcept {
            FinalizeMutex(&mutex_lock);
        }

        inline void lock() noexcept EXCLUSIVE_LOCK_FUNCTION() SHARED_LOCK_FUNCTION() {
            if(mutex_lock.curState == 0) {
                nn::os::InitializeMutex(&mutex_lock, false, 0); // trampolined.
            }
            nn::os::LockMutex(&mutex_lock);
        }

        inline void unlock() noexcept UNLOCK_FUNCTION() {
            nn::os::UnlockMutex(&mutex_lock);
        }

        [[nodiscard]] inline bool try_lock() noexcept EXCLUSIVE_TRYLOCK_FUNCTION(true) SHARED_TRYLOCK_FUNCTION(true) {
            if(mutex_lock.curState == 0) {
                nn::os::InitializeMutex(&mutex_lock, false, 0); // trampolined.
            }
            return nn::os::TryLockMutex(&mutex_lock);
        }

        [[nodiscard]] inline bool is_locked_by_current_thread() const noexcept {
            return nn::os::IsMutexLockedByCurrentThread(&mutex_lock);
        }
    };
}