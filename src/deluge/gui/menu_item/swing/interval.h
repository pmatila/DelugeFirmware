/*
 * Copyright (c) 2014-2023 Synthstrom Audible Limited
 *
 * This file is part of The Synthstrom Audible Deluge Firmware.
 *
 * The Synthstrom Audible Deluge Firmware is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program.
 * If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once
#include "gui/menu_item/sync_level.h"
#include "model/song/song.h"

namespace deluge::gui::menu_item::swing {

class Interval : public SyncLevel {
public:
	using SyncLevel::SyncLevel;

	void readCurrentValue() override { this->setValue(currentSong->swingInterval); }
	void writeCurrentValue() override { currentSong->changeSwingInterval(this->getValue()); }
	// triplet/dotted not yet supported
	size_t size() override { return NUM_SWING_INTERVALS; }
	void selectEncoderAction(int32_t offset) override {
		this->setValue(wrapSwingIntervalSyncLevel(this->getValue() + offset));
		Value::selectEncoderAction(offset);
	}
};

} // namespace deluge::gui::menu_item::swing
