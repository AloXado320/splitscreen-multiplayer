/**********************************************************************
                                                                       
   ultra64 displaylist C source file ( sand )
                                                                       
**********************************************************************/

/* POLYGON TOTAL (126) */

#define ShapeColor(r,g,b) gdSPDefLights1(r/4,g/4,b/4,r,g,b,0x28,0x28,0x28)

#define	softspriteON	1

#define LIGHT_X 0x28
#define LIGHT_Y 0x28
#define LIGHT_Z 0x28
#define SCALE 0.25

/*---------------------------------------------------------------------
   Light Data                                                          
---------------------------------------------------------------------*/


static long long dmmy1_sand = 0;
static Lights1 light_sand[] = {
	ShapeColor( 200,200,  0 ),  /* attr (50) */
	ShapeColor( 200,200,  0 ),  /* attr (52) */
	ShapeColor( 200,200,  0 ),  /* attr (51) */
	ShapeColor( 200,200,  0 ),  /* attr (56) */
	ShapeColor( 200,200,  0 ),  /* attr (57) */
	ShapeColor( 200,200,  0 ),  /* attr (54) */
	ShapeColor( 200,200,  0 ),  /* attr (53) */
	ShapeColor( 200,200,  0 ),  /* attr (55) */
	ShapeColor(   0,255,  0 ),  /* attr (5) */
	ShapeColor(   0,150,  0 ),  /* attr (6) */
	ShapeColor( 210,  0,  0 ),  /* attr (34) */
	ShapeColor( 255,  0,  0 ),  /* attr (35) */
	ShapeColor( 150, 50, 50 ),  /* attr (33) */
	ShapeColor( 170, 20, 20 ),  /* attr (38) */
	ShapeColor( 100,100,  0 ),  /* attr (40) */
	ShapeColor( 100,100,  0 ),  /* attr (42) */
	ShapeColor( 100,100,  0 ),  /* attr (41) */
	ShapeColor( 100,100,  0 ),  /* attr (46) */
	ShapeColor( 100,100,  0 ),  /* attr (47) */
	ShapeColor( 100,100,  0 ),  /* attr (44) */
	ShapeColor( 100,100,  0 ),  /* attr (43) */
	ShapeColor( 100,100,  0 ),  /* attr (45) */
	ShapeColor( 150,  0,  0 ),  /* attr (3) */
};
static long long dmmy2_sand = 0;

/*---------------------------------------------------------------------
   Vtx Data                                                            
---------------------------------------------------------------------*/

static Vtx vtx_sand[] = {
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,  -1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,  -1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,  -2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{  2350,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{  4750,      0,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  4750,      0,  -2300}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  4750,      0,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{  2350,      0,  -4700}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{  4750,      0,  -2300}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{  2350,      0,  -4700}, 0, {0, 0}, {  -6,  126,    6, 0 }}},
    {{{ -2300,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{     0,      0,  -4700}, 0, {0, 0}, {   0,  126,    9, 0 }}},
    {{{ -4700,      0,  -2300}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -4700,      0,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -4700,      0,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -2300,      0,  -4700}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{ -4700,      0,  -2300}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{ -2300,      0,  -4700}, 0, {0, 0}, {   6,  126,    6, 0 }}},
    {{{  2350,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{  4750,      0,   2300}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  4750,      0,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  4750,      0,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {  -9,  126,    0, 0 }}},
    {{{  2350,      0,   4700}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{  4750,      0,   2300}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{  2350,      0,   4700}, 0, {0, 0}, {  -6,  126,   -6, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{ -2300,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{     0,      0,   4700}, 0, {0, 0}, {   0,  126,   -9, 0 }}},
    {{{ -4700,      0,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -4700,      0,   2300}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -4700,      0,      0}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   9,  126,    0, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -2300,      0,   4700}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -4700,      0,   2300}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -2300,      0,   4700}, 0, {0, 0}, {   6,  126,   -6, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, { -15,  125,  -15, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, { -15,  125,  -15, 0 }}},
    {{{  -950,      0,  -2000}, 0, {0, 0}, { -15,  125,  -15, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, { -18,  124,  -16, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, { -18,  124,  -16, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, { -18,  124,  -16, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,  -1000}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, { -22,  124,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, { -18,  124,   16, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, { -18,  124,   16, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, { -18,  124,   16, 0 }}},
    {{{ -1950,      0,   1000}, 0, {0, 0}, { -15,  125,   15, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, { -15,  125,   15, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, { -15,  125,   15, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  -950,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{    50,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {   0,  124,   24, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {  21,  123,   19, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {  21,  123,   19, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {  21,  123,   19, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {  17,  124,   17, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {  17,  124,   17, 0 }}},
    {{{  1050,      0,   2000}, 0, {0, 0}, {  17,  124,   17, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,   1000}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,  -1000}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,      0}, 0, {0, 0}, {  27,  123,    0, 0 }}},
    {{{  2050,      0,  -1000}, 0, {0, 0}, {  17,  124,  -17, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {  17,  124,  -17, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {  17,  124,  -17, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {  21,  123,  -19, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {  21,  123,  -19, 0 }}},
    {{{  2050,      0,  -1000}, 0, {0, 0}, {  21,  123,  -19, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{     0,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{  1050,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{     0,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{     0,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{  -950,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{    50,      0,  -2000}, 0, {0, 0}, {   0,  124,  -24, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, {   0,   89,   89, 0 }}},
    {{{   250,      0,   -500}, 0, {0, 0}, {   0,   89,   89, 0 }}},
    {{{  -250,      0,   -500}, 0, {0, 0}, {   0,   89,   89, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, { -89,   89,    0, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, { -89,   89,    0, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, { -89,   89,    0, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {  89,   89,    0, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, {  89,   89,    0, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {  89,   89,    0, 0 }}},
    {{{  -250,      0,    500}, 0, {0, 0}, {   0,   89,  -89, 0 }}},
    {{{   250,      0,    500}, 0, {0, 0}, {   0,   89,  -89, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, {   0,   89,  -89, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {  61,   92,   61, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, {  61,   92,   61, 0 }}},
    {{{  -250,      0,   -500}, 0, {0, 0}, {  61,   92,   61, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, { -61,   92,   61, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, { -61,   92,   61, 0 }}},
    {{{   250,      0,   -500}, 0, {0, 0}, { -61,   92,   61, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {  61,   92,  -61, 0 }}},
    {{{  -250,      0,    500}, 0, {0, 0}, {  61,   92,  -61, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, {  61,   92,  -61, 0 }}},
    {{{   250,      0,    500}, 0, {0, 0}, { -61,   92,  -61, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, { -61,   92,  -61, 0 }}},
    {{{     0,   -500,      0}, 0, {0, 0}, { -61,   92,  -61, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1550,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,   -700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,   -500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,  -1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   800,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{   250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{    50,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -250,      0,    500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -700,      0,   1500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,   -250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,    700}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  -500,      0,    250}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1450,      0,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,  -1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,      0}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,  -2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,  -1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,  -1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,  -3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{     0,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  3350,   -100,   1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1250,   -100,   2500}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -2500,   -100,   1150}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -3350,   -100,   1650}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{ -1650,   -100,   3350}, 0, {0, 0}, {   0,  127,    0, 0 }}},
    {{{  5000,    400,  -1450}, 0, {0, 0}, {   0, -127,    0, 0 }}},
    {{{  5000,    400,   2300}, 0, {0, 0}, {   0, -127,    0, 0 }}},
    {{{   600,    400,  -1450}, 0, {0, 0}, {   0, -127,    0, 0 }}},
    {{{  5000,    400,   2300}, 0, {0, 0}, {   0, -127,    0, 0 }}},
    {{{   600,    400,   2300}, 0, {0, 0}, {   0, -127,    0, 0 }}},
    {{{   600,    400,  -1450}, 0, {0, 0}, {   0, -127,    0, 0 }}},
};

/*---------------------------------------------------------------------
   Gfx Data                                                            
---------------------------------------------------------------------*/

Gfx RCP_sand[] = {

	gsSPNumLights(1),
	gsSPLight((&light_sand[0].l[0]),1),
	gsSPLight((&light_sand[0].a),2),
	
	gsSPVertex(&vtx_sand[0], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[1].l[0]),1),
	gsSPLight((&light_sand[1].a),2),
	
	gsSPVertex(&vtx_sand[12], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[2].l[0]),1),
	gsSPLight((&light_sand[2].a),2),
	
	gsSPVertex(&vtx_sand[24], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[3].l[0]),1),
	gsSPLight((&light_sand[3].a),2),
	
	gsSPVertex(&vtx_sand[30], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[4].l[0]),1),
	gsSPLight((&light_sand[4].a),2),
	
	gsSPVertex(&vtx_sand[42], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[5].l[0]),1),
	gsSPLight((&light_sand[5].a),2),
	
	gsSPVertex(&vtx_sand[48], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[6].l[0]),1),
	gsSPLight((&light_sand[6].a),2),
	
	gsSPVertex(&vtx_sand[60], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[7].l[0]),1),
	gsSPLight((&light_sand[7].a),2),
	
	gsSPVertex(&vtx_sand[66], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[8].l[0]),1),
	gsSPLight((&light_sand[8].a),2),
	
	gsSPVertex(&vtx_sand[72], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[87], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[102], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[117], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[132], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[147], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[162], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[177], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[192], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[207], 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[9].l[0]),1),
	gsSPLight((&light_sand[9].a),2),
	
	gsSPVertex(&vtx_sand[216], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[231], 15, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSPVertex(&vtx_sand[246], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[10].l[0]),1),
	gsSPLight((&light_sand[10].a),2),
	
	gsSPVertex(&vtx_sand[258], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[11].l[0]),1),
	gsSPLight((&light_sand[11].a),2),
	
	gsSPVertex(&vtx_sand[270], 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[12].l[0]),1),
	gsSPLight((&light_sand[12].a),2),
	
	gsSPVertex(&vtx_sand[279], 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[13].l[0]),1),
	gsSPLight((&light_sand[13].a),2),
	
	gsSPVertex(&vtx_sand[288], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[14].l[0]),1),
	gsSPLight((&light_sand[14].a),2),
	
	gsSPVertex(&vtx_sand[300], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[15].l[0]),1),
	gsSPLight((&light_sand[15].a),2),
	
	gsSPVertex(&vtx_sand[312], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[16].l[0]),1),
	gsSPLight((&light_sand[16].a),2),
	
	gsSPVertex(&vtx_sand[324], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[17].l[0]),1),
	gsSPLight((&light_sand[17].a),2),
	
	gsSPVertex(&vtx_sand[330], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[18].l[0]),1),
	gsSPLight((&light_sand[18].a),2),
	
	gsSPVertex(&vtx_sand[342], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[19].l[0]),1),
	gsSPLight((&light_sand[19].a),2),
	
	gsSPVertex(&vtx_sand[348], 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 10, 11, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[20].l[0]),1),
	gsSPLight((&light_sand[20].a),2),
	
	gsSPVertex(&vtx_sand[360], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[21].l[0]),1),
	gsSPLight((&light_sand[21].a),2),
	
	gsSPVertex(&vtx_sand[366], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),

	gsSPNumLights(1),
	gsSPLight((&light_sand[22].l[0]),1),
	gsSPLight((&light_sand[22].a),2),
	
	gsSPVertex(&vtx_sand[372], 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 4, 5, 0),
	gsSPEndDisplayList()
};

/*=====================================================================
   end of shape                                                        
=====================================================================*/

