// SPDX-License-Identifier: GPL-2.0
// Convenience classes defining owning pointers to C-objects that
// automatically clean up the objects if the pointers go out of
// scope. Based on unique_ptr<>.
// In the future, we should replace these by real destructors.
#ifndef OWNING_PTR_H
#define OWNING_PTR_H

#include <memory>
#include <cstdlib>

struct dive_trip;

void free_trip(struct dive_trip *);

// Classes used to automatically call the appropriate free_*() function for owning pointers that go out of scope.
struct TripDeleter {
	void operator()(dive_trip *t) { free_trip(t); }
};

// Owning pointers to dive, dive_trip, dive_site and event objects.
using OwningTripPtr = std::unique_ptr<dive_trip, TripDeleter>;

#endif
