// Copyright 2024 The excelize Authors. All rights reserved. Use of this source
// code is governed by a BSD-style license that can be found in the LICENSE file.
//
// Package excelize-py is a Python port of Go Excelize library, providing a set
// of functions that allow you to write and read from XLAM / XLSM / XLSX / XLTM
// / XLTX files. Supports reading and writing spreadsheet documents generated
// by Microsoft Excel™ 2007 and later. Supports complex components by high
// compatibility, and provided streaming API for generating or reading data from
// a worksheet with huge amounts of data. This library needs Python version 3.9
// or later.

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct Interface {
	int Type;
	int Integer;
	char* String;
	double Float64;
	bool Boolean;
};

// Options define the options for opening and reading the spreadsheet.
//
// MaxCalcIterations specifies the maximum iterations for iterative
// calculation, the default value is 0.
//
// Password specifies the password of the spreadsheet in plain text.
//
// RawCellValue specifies if apply the number format for the cell value or get
// the raw value.
//
// UnzipSizeLimit specifies to unzip size limit in bytes on open the
// spreadsheet, this value should be greater than or equal to
// UnzipXMLSizeLimit, the default size limit is 16GB.
//
// UnzipXMLSizeLimit specifies the memory limit on unzipping worksheet and
// shared string table in bytes, worksheet XML will be extracted to system
// temporary directory when the file size is over this value, this value
// should be less than or equal to UnzipSizeLimit, the default value is
// 16MB.
//
// ShortDatePattern specifies the short date number format code. In the
// spreadsheet applications, date formats display date and time serial numbers
// as date values. Date formats that begin with an asterisk (*) respond to
// changes in regional date and time settings that are specified for the
// operating system. Formats without an asterisk are not affected by operating
// system settings. The ShortDatePattern used for specifies apply date formats
// that begin with an asterisk.
//
// LongDatePattern specifies the long date number format code.
//
// LongTimePattern specifies the long time number format code.
//
// CultureInfo specifies the country code for applying built-in language number
// format code these effect by the system's local language settings.
struct Options {
	unsigned int MaxCalcIterations;
	char* Password;
	bool RawCellValue;
	long int UnzipSizeLimit;
	long int UnzipXMLSizeLimit;
	char* ShortDatePattern;
	char* LongDatePattern;
	char* LongTimePattern;
	unsigned char CultureInfo;
};

// Border directly maps the border settings of the cells.
struct Border {
    char* Type;
	char* Color;
	int Style;
};

// Fill directly maps the fill settings of the cells.
struct Fill {
	char* Type;
	int Pattern;
	int ColorLen;
	char** Color;
	int Shading;
};

// Font directly maps the font settings of the fonts.
struct Font {
	bool Bold;
	bool Italic;
	char* Underline;
	char* Family;
	double Size;
	bool Strike;
	char* Color;
	int ColorIndexed;
	int* ColorTheme;
	double ColorTint;
	char* VertAlign;
};

// Alignment directly maps the alignment settings of the cells.
struct Alignment {
	char* Horizontal;
	int Indent;
	bool JustifyLastLine;
	unsigned int ReadingOrder;
	int RelativeIndent;
	bool ShrinkToFit;
	int TextRotation;
	char* Vertical;
	bool WrapText;
};

// Protection directly maps the protection settings of the cells.
struct Protection {
	bool Hidden;
	bool Locked;
};

// Style directly maps the style settings of the cells.
struct Style {
    int BorderLen;
    struct Border *Border;
	struct Fill Fill;
	struct Font *Font;
	struct Alignment *Alignment;
	struct Protection *Protection;
	int NumFmt;
	int* DecimalPlaces;
	char** CustomNumFmt;
	bool NegRed;
};

// GraphicOptions directly maps the format settings of the picture.
struct GraphicOptions {
	char* AltText;
	bool* PrintObject;
	bool* Locked;
	bool LockAspectRatio;
	bool AutoFit;
	bool AutoFitIgnoreAspect;
	int OffsetX;
	int OffsetY;
	double ScaleX;
	double ScaleY;
	char* Hyperlink;
	char* HyperlinkType;
	char* Positioning;
};

// RichTextRun directly maps the settings of the rich text run.
struct RichTextRun {
	struct Font *Font;
	char* Text;
};

// ChartNumFmt directly maps the number format settings of the chart.
struct ChartNumFmt {
	char* CustomNumFmt;
	bool SourceLinked;
};

// ChartAxis directly maps the format settings of the chart axis.
struct ChartAxis {
	bool None;
	bool MajorGridLines;
	bool MinorGridLines;
	double MajorUnit;
	unsigned char TickLabelPosition;
	int TickLabelSkip;
	bool ReverseOrder;
	bool Secondary;
	double* Maximum;
	double* Minimum;
	struct Alignment Alignment;
	struct Font Font;
	double LogBase;
	struct ChartNumFmt NumFmt;
	int TitleLen;
	struct RichTextRun *Title;
};

// ChartDimension directly maps the dimension of the chart.
struct ChartDimension {
	unsigned int Width;
	unsigned int Height;
};

// ChartPlotArea directly maps the format settings of the plot area.
struct ChartPlotArea {
	int SecondPlotValues;
	bool ShowBubbleSize;
	bool ShowCatName;
	bool ShowLeaderLines;
	bool ShowPercent;
	bool ShowSerName;
	bool ShowVal;
	struct Fill Fill;
	struct ChartNumFmt NumFmt;
};

// ChartLegend directly maps the format settings of the chart legend.
struct ChartLegend {
	char* Position;
	bool ShowLegendKey;
};

// ChartMarker directly maps the format settings of the chart marker.
struct ChartMarker {
	struct Fill Fill;
	char* Symbol;
	int Size;
};

// ChartLine directly maps the format settings of the chart line.
struct ChartLine {
	unsigned char Type;
	bool Smooth;
	double Width;
};

// ChartSeries directly maps the format settings of the chart series.
struct ChartSeries {
	char* Name;
	char* Categories;
	char* Values;
	char* Sizes;
	struct Fill Fill;
	struct ChartLine Line;
	struct ChartMarker Marker;
	unsigned char DataLabelPosition;
};

// Chart directly maps the format settings of the chart.
struct Chart {
	unsigned char Type;
	int SeriesLen;
	struct ChartSeries *Series;
	struct GraphicOptions Format;
	struct ChartDimension Dimension;
	struct ChartLegend Legend;
	int TitleLen;
	struct RichTextRun *Title;
	bool* VaryColors;
	struct ChartAxis XAxis;
	struct ChartAxis YAxis;
	struct ChartPlotArea PlotArea;
	struct Fill Fill;
	struct ChartLine Border;
	char* ShowBlanksAs;
	int BubbleSize;
	int HoleSize;
};

struct CoordinatesToCellNameResult {
    char* cell;
    char* err;
};

struct OptionsResult {
	int idx;
    char* err;
};

struct GetCellValueResult {
    char* val;
    char* err;
};

struct Row {
	int CellLen;
	char** Cell;
};

struct GetRowsResult {
    int RowLen;
    struct Row *Row;
    char* err;
};

struct NewSheetResult {
    int idx;
    char* err;
};

struct NewStyleResult {
    int style;
    char* err;
};

struct GetStyleResult {
	struct Style style;
	char* err;
};
