// Settings.h
//
// Viewer settings stored as human-readable symbolic expressions.
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
#include <Foundation/tString.h>
#include <Math/tColour.h>


namespace Viewer
{
	struct Settings
	{
		Settings()							{ Reset(); }
		int WindowX;
		int WindowY;
		int WindowW;
		int WindowH;
		bool ShowMenuBar;
		bool ShowNavBar;
		bool ShowImageDetails;
		bool ShowPixelEditor;
		bool ShowFrameScrubber;
		bool ContentViewShow;
		float ThumbnailWidth;
		enum class SortKeyEnum
		{
			FileName,
			FileModTime,
			FileSize,
			FileType,
			ImageArea,
			ImageWidth,
			ImageHeight
		};
		int SortKey;						// Matches SortKeyEnum values.
		bool SortAscending;					// Sort direction.

		int OverlayCorner;
		bool Tile;

		enum class BGStyle
		{
			None,
			Checkerboard,
			Black,
			Grey,
			White
		};
		int BackgroundStyle;
		bool BackgroundExtend;				// Extend background past image bounds.
		bool TransparentWorkArea;

		int ResampleFilter;					// Matches tImage::tResampleFilter.
		int ResampleEdgeMode;				// Matches tImage::tResampleEdgeMode.
		int ResampleFilterRotateUp;			// Matches tImage::tResampleFilter.
		int ResampleFilterRotateDown;		// Matches tImage::tResampleFilter.

		enum class RotMode
		{
			Fill,
			Crop,
			CropResize,
			NumModes
		};
		int RotateMode;
		bool ConfirmDeletes;
		bool ConfirmFileOverwrites;
		bool SlideshowLooping;
		bool SlideshowProgressArc;
		double SlideshowPeriod;

		tString SaveSubFolder;
		int		SaveFileType;
		int		SaveFileTypeMultiFrame;
		bool	SaveFileTargaRLE;
		int		SaveFileJpegQuality;		// E [1, 100]
		bool	SaveFileWebpLossy;
		float	SaveFileWebpQualComp;		// E [0.0, 100.0]
		bool	SaveFileTiffZLibDeflate;

		int SaveFileWebpDurOverride;		// E [-1, inf]. In ms.
		int SaveFileGifDurOverride;			// E [-1, inf]. In 1/100 seconds.
		int SaveFileApngDurOverride;		// E [-1, 65535]. In ms.
		int SaveFileTiffDurOverride;		// E [-1, inf]. In ms.

		int SaveFileWebpDurMultiFrame;		// E [0, inf]. In ms.
		int SaveFileGifDurMultiFrame;		// E [0, inf]. In 1/100 seconds.
		int SaveFileApngDurMultiFrame;		// E [0, 65536]. In ms.
		int SaveFileTiffDurMultiFrame;		// E [0, inf]. In ms.
		enum class SizeMode
		{
			Percent,
			SetWidthAndHeight,
			SetWidthRetainAspect,
			SetHeightRetainAspect
		};
		int SaveAllSizeMode;
		int CropAnchor;						// E [-1, 9] with 4 being the default (middle), 0 being top-left, and -1 being 'cursor position'.
		tColouri FillColour;
		int ResizeAspectNum;
		int ResizeAspectDen;
		int ResizeAspectMode;				// 0 = Crop Mode. 1 = Letterbox Mode.
		int MaxImageMemMB;					// Max image mem before unloading images.
		int MaxCacheFiles;					// Max number of cache files before removing oldest.
		int MaxUndoSteps;
		bool StrictLoading;					// No attempt to display ill-formed images.
		bool DetectAPNGInsidePNG;			// Look for APNG data (animated) hidden inside a regular PNG file.
		int MipmapFilter;					// Matches tImage::tResampleFilter. Use None for no mipmaps.
		bool MipmapChaining;				// True for faster mipmap generation. False for a lot slower and slightly better results.
		bool AutoPropertyWindow;			// Auto display property editor window for supported file types.
		bool AutoPlayAnimatedImages;		// Automatically play animated gifs, apngs, and WebPs.
		float MonitorGamma;					// Used when displaying HDR formats to do gamma correction.

		void Load(const tString& filename);
		bool Save(const tString& filename);
		void Reset();
		void ResetBehaviourSettings();
		void ResetUISettings();
	};

	extern Settings Config;
}
