// TacentView.h
//
// A texture viewer for various formats.
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
#include <Math/tVector2.h>
#include <Math/tVector4.h>
#include <System/tCmdLine.h>
#include "Settings.h"
namespace Viewer { class Image; }
class tColouri;


namespace Viewer
{
	extern Settings Config;
	extern Image* CurrImage;
	extern tString ImagesDir;
	extern tList<tStringItem> ImagesSubDirs;
	extern tList<Viewer::Image> Images;
	extern tItList<Viewer::Image> ImagesLoadTimeSorted;
	extern tCmdLine::tParam ImageFileParam;
	extern tColouri PixelColour;
	extern Viewer::Image DefaultThumbnailImage;
	extern Viewer::Image UpFolderImage;
	extern Viewer::Image PlayImage;
	extern Viewer::Image PlayRevImage;
	extern Viewer::Image StopImage;
	extern Viewer::Image StopRevImage;
	extern Viewer::Image PlayLoopImage;
	extern Viewer::Image PlayOnceImage;
	extern Viewer::Image PrevImage;
	extern Viewer::Image NextImage;
	extern Viewer::Image SkipBeginImage;
	extern Viewer::Image SkipEndImage;
	extern bool CropMode;
	extern bool DeleteAllCacheFilesOnExit;
	extern bool PendingTransparentWorkArea;
	extern double SlideshowCountdown;
	extern int CursorX;
	extern int CursorY;
	extern float RotateAnglePreview;

	extern const tMath::tVector4 ColourEnabledTint;
	extern const tMath::tVector4 ColourDisabledTint;
	extern const tMath::tVector4 ColourBG;
	extern const tMath::tVector4 ColourPressedBG;
	extern const tMath::tVector4 ColourClear;

	const int TopUIHeight			= 26;
	const float DialogOrigin		= 32.0f;
	const float DialogDelta			= 19.0f;
	const double DisappearDuration	= 4.0;

	// Helper to display a little (?) mark which shows a tooltip when hovered.
	void ShowHelpMark(const char* desc);
	void ShowToolTip(const char* desc);
	void PopulateImages();
	void PopulateImagesSubDirs();
	Image* FindImage(const tString& filename);
	void SetCurrentImage(const tString& currFilename = tString());
	void LoadCurrImage();
	bool ChangeScreenMode(bool fullscreeen, bool force = false);
	void SortImages(Settings::SortKeyEnum, bool ascending);
	bool DeleteImageFile(const tString& imgFile, bool tryUseRecycleBin);
	void SetWindowTitle();
	void ZoomFit();
	void ZoomDownscaleOnly();
	void ResetPan(bool resetX = true, bool resetY = true);
	tMath::tVector2 GetDialogOrigin(float index);

	void Undo();
	void Redo();

	void ConvertScreenPosToImagePos
	(
		int& imgX, int& imgY,
		const tMath::tVector2& scrPos, const tMath::tVector4& lrtb,
		const tMath::tVector2& uvMarg, const tMath::tVector2& uvOff
	);
	void ConvertImagePosToScreenPos
	(
		tMath::tVector2& scrPos,
		int imgX, int imgY, const tMath::tVector4& lrtb,
		const tMath::tVector2& uvMarg, const tMath::tVector2& uvOff
	);
}
