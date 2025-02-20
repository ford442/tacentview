// Dialogs.h
//
// Various dialogs and helpers including a log window, info overlay, cheatsheet, help window, and about window.
//
// Copyright (c) 2019, 2020, 2021 Tristan Grimmer.
// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby
// granted, provided that the above copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
// AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#pragma once


namespace Viewer
{
	void ShowImageDetailsOverlay(bool* popen, float x, float y, float w, float h, int cursorX, int cursorY, float zoom);
	void ShowPixelEditorOverlay(bool* popen);
	void ShowCheatSheetPopup(bool* popen);
	void ShowAboutPopup(bool* popen);
	void ColourCopyAs();
	void DoDeleteFileModal();
	void DoDeleteFileNoRecycleModal();
	void DoRenameModal(bool justOpened);
	void DoSnapMessageNoFileBrowseModal(bool justOpened);
	void DoSnapMessageNoFrameTransModal(bool justOpened);

	// Parts of this class are a modification of the one that ships with Dear ImGui. The DearImGui
	// licence (MIT) may be found in the txt file Licence_DearImGui_MIT.txt in the Data folder.
	class NavLogBar
	{
	public:
		NavLogBar()												: LogScrollToBottom(true) { ClearLog(); }
		void Draw();
		void SetShowLog(bool enabled)							{ ShowLog = enabled; }
		bool GetShowLog() const									{ return ShowLog; }
		void AddLog(const char* fmt, ...) IM_FMTARGS(2);

	private:
		void ClearLog();
		void DrawLog();

		bool ShowLog = false;
		ImGuiTextBuffer LogBuf;
		ImGuiTextFilter LogFilter;

		// Index to lines offset. We maintain this with AddLog() calls, allowing us to have a random access on lines.
		ImVector<int> LogLineOffsets;
		bool LogScrollToBottom;
	};
}
