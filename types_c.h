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

struct Border {
    char* Type;
	char* Color;
	int Style;
};

struct Fill {
	char* Type;
	int Pattern;
	int ColorLen;
	char** Color;
	int Shading;
};

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

struct Protection {
	bool Hidden;
	bool Locked;
};

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

struct OptionsResult {
	int idx;
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
