// SPDX-License-Identifier: GPL-2.0
// A structure that contains all the data we store in a divelog files
#ifndef DIVELOG_H
#define DIVELOG_H

#include <memory>

struct dive_table;
struct trip_table;
class dive_site_table;
struct device_table;
struct filter_preset_table;

struct divelog {
	std::unique_ptr<dive_table> dives;
	std::unique_ptr<trip_table> trips;
	std::unique_ptr<dive_site_table> sites;
	std::unique_ptr<device_table> devices;
	std::unique_ptr<filter_preset_table> filter_presets;
	bool autogroup;

	divelog();
	~divelog();
	divelog(divelog &&); // move constructor (argument is consumed).
	divelog &operator=(divelog &&); // move assignment (argument is consumed).

	void delete_single_dive(int idx);
	void clear();
};

extern struct divelog divelog;

#endif
