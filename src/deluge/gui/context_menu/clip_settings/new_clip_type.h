/*
 * ContextMenu\Clip_Settings\New_Clip_Type.h
 *
 *  Created on: 4 Aug 2024
 *      Author: Sean
 */

#pragma once

#include "gui/context_menu/context_menu.h"
#include "hid/led/indicator_leds.h"

using namespace indicator_leds;

namespace deluge::gui::context_menu::clip_settings {

class NewClipType final : public ContextMenu {

public:
	NewClipType() = default;
	void selectEncoderAction(int8_t offset) override;
	bool setupAndCheckAvailability();
	bool canSeeViewUnderneath() override { return true; }
	bool acceptCurrentOption() override; // If returns false, will cause UI to exit
	ActionResult buttonAction(deluge::hid::Button b, bool on, bool inCardRoutine) override;
	void updateSelectedOption();
	void updateOutputToCreate();

	LED getLedFromOption(int32_t option);
	void disableLedForOption(int32_t option);
	void blinkLedForOption(int32_t option);

	OutputType toCreate = OutputType::AUDIO;

	/// Title
	char const* getTitle() override;

	/// Options
	Sized<const char**> getOptions() override;
	ActionResult padAction(int32_t x, int32_t y, int32_t on) override;
};

extern NewClipType newClipType;
} // namespace deluge::gui::context_menu::clip_settings
