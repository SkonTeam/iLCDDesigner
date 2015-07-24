#define  GraphicOrientation ScreenOrientation
#define  DisplayAdjust GraphAdjust
#define  DisplayAreaAdjust GraphAdjust
#define  EllipseMode CircleMode

enum DisplayMode{
	DISPOFFPWROFF = 0,
	DISPON = 1,
	DISPONLIGHTON = 2
};
enum ScreenOrientation{
	LANDSCAPE = 0,
	PORTRAIT = 1,
	LANDSCAPEINVERSED = 2,
	PORTRAITINVERSED = 3
}; //GraphicOrientation
enum GraphicAlign{
	CENTERHORIZ = 0x01,
	CENTERVERT = 0x02,
	RIGHTJUSTIFY = 0x04,
	BOTTOMJUSTIFY = 0x08,
	ALIGNON = 0x80
};
enum TextAlign{
	TEXTCENTERHORIZ = 0x01,
	TEXTCENTERVERT = 0x02,
	TEXTRIGHTJUSTIFY = 0x04,
	TEXTBOTTOMJUSTIFY = 0x08,
	DONOTWRAPTEXT = 0x10,
	ADDHORIZSPACE = 0x20,
	ADDVERTSPACE = 0x40,
	TEXTALIGNON = 0x80
};
enum BacklightMode{
	BACKLIGHTOFF = 0,
	BACKLIGHTON = 1,
	BACKLIGHTBLINK = 2,
	ACKLIGHTFADE = 3
};
enum LineDrawMode{
	UPTODASH = 0,
	SPECIFIEDENDPOINT = 1,
	MULTLINETHICK = 2
};
enum GradientMode{
	HORIZGRAD = 0,
	VERTGRAD = 1,
	HORIZSYMGRAD = 2,
	VERTSYMGRAD = 3,
	BUTTONIZED = 4
};
enum GraphAdjust{
	BRIGHTNESS = 0x01,
	CONTRAST = 0x02,
	HUE = 0x04,
	SATURATION = 0x08,
	INVERT = 0x10
}; //DisplayAdjust,DisplayAreaAdjust

enum RectangleMode {
	RECTROUNDEDCORNERS = 0x01,
	RECTDROPSHADOW = 0x02,
	RECTSURROUNDBGRCOLOR = 0x04,
	RECTFILLBGRCOLOR = 0x08,
	RECTFILLFGRCOLOR = 0x18,
	RECTFILLPATTERN = 0x20,
	RECTNOFRAME = 0x40,
	RECTSHADOWALPHABLEND = 0x80
};
enum CircleMode{
	CIRCLEDROPSHADOW = 0x02,
	CIRCLEFILLBGRCOLOR = 0x08,
	CIRCLEFILLFGRCOLOR = 0x18,
	CIRCLEFILLPATTERN = 0x20 ,
	CIRCLENOOUTLINE = 0x40,
	CIRCLESHADOWALPHABLEND = 0x80
}; //EllipseMode
enum OutputMode{
	OUTPUTOFF = 0,
	OUTPUTON = 1,
	OUTPUTBLINK = 2
};
enum RelayMode{
	RELAYOFF = 0,
	RELAYON = 1,
	RELAYPWM = 2
};
enum FileAccessMode{
	READ = 0x52,
	WRITE = 0x57,
	APPEND = 0x41
};
enum FlashUpdateFlags{
	NOREBOOT = 0x01,
	NOVERIF = 0x02,
	VERBOSE = 0x80
};
enum PortNumbers{
	NULLPRT = 0x00,
	SERIALPRT0 = 0x02,
	SERIALPRT1 = 0x04,
	USB = 0x08,
	I2C = 0x10,
	SPI = 0x20,
	ETHERNET = 0x40
};

inline DisplayMode operator|(DisplayMode a, DisplayMode b)
{
	return static_cast<DisplayMode>(static_cast<int>(a) | static_cast<int>(b));
}

inline ScreenOrientation operator|(ScreenOrientation a, ScreenOrientation b)
{
	return static_cast<ScreenOrientation>(static_cast<int>(a) | static_cast<int>(b));
}

inline GraphicAlign operator|(GraphicAlign a, GraphicAlign b)
{
	return static_cast<GraphicAlign>(static_cast<int>(a) | static_cast<int>(b));
}
inline TextAlign operator|(TextAlign a, TextAlign b)
{
	return static_cast<TextAlign>(static_cast<int>(a) | static_cast<int>(b));
}
inline BacklightMode operator|(BacklightMode a, BacklightMode b)
{
	return static_cast<BacklightMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline LineDrawMode operator|(LineDrawMode a, LineDrawMode b)
{
	return static_cast<LineDrawMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline GradientMode operator|(GradientMode a, GradientMode b)
{
	return static_cast<GradientMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline GraphAdjust operator|(GraphAdjust a, GraphAdjust b)
{
	return static_cast<GraphAdjust>(static_cast<int>(a) | static_cast<int>(b));
}
inline RectangleMode operator|(RectangleMode a, RectangleMode b)
{
	return static_cast<RectangleMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline CircleMode operator|(CircleMode a, CircleMode b)
{
	return static_cast<CircleMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline OutputMode operator|(OutputMode a, OutputMode b)
{
	return static_cast<OutputMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline RelayMode operator|(RelayMode a, RelayMode b)
{
	return static_cast<RelayMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline FileAccessMode operator|(FileAccessMode a, FileAccessMode b)
{
	return static_cast<FileAccessMode>(static_cast<int>(a) | static_cast<int>(b));
}
inline PortNumbers operator|(PortNumbers a, PortNumbers b)
{
	return static_cast<PortNumbers>(static_cast<int>(a) | static_cast<int>(b));
}