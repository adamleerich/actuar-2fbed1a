/*  actuar: Actuarial Functions and Heavy Tailed Distributions
 *
 *  Table of functions internal to the package. First element is an
 *  argument to one of actuar_do_dpq or actuar_do_random, functions
 *  callable from .External(); second element is the C function
 *  actually called; third element is a code used in the latter.
 *
 *  Idea taken from R sources (see src/main/names.c).
 *
 *  AUTHOR: Vincent Goulet <vincent.goulet@act.ulaval.ca>
 */

#include <Rinternals.h>
#include "actuar.h"

/* DENSITY, CUMULATIVE PROBABILITY AND QUANTILE FUNCTIONS,
 * RAW AND LIMITED MOMENTS */
dpq_tab_struct dpq_tab[] = {
    /* One parameter distributions */
    {"mexp",            actuar_do_dpq1,        1},
    {"dinvexp",         actuar_do_dpq1,        2},
    {"pinvexp",         actuar_do_dpq1,        3},
    {"qinvexp",         actuar_do_dpq1,        4},
    {"minvexp",         actuar_do_dpq1,        5},
    {"mgfexp",          actuar_do_dpq1,        6},
    {"dlogarithmic",    actuar_do_dpq1,       101},
    {"plogarithmic",    actuar_do_dpq1,       102},
    {"qlogarithmic",    actuar_do_dpq1,       103},
    {"dztpois",         actuar_do_dpq1,       104},
    {"pztpois",         actuar_do_dpq1,       105},
    {"qztpois",         actuar_do_dpq1,       106},
    {"dztgeom",         actuar_do_dpq1,       107},
    {"pztgeom",         actuar_do_dpq1,       108},
    {"qztgeom",         actuar_do_dpq1,       109},
    /* Two parameter distributions */
    {"mgamma",          actuar_do_dpq2,         1},
    {"dinvgamma",       actuar_do_dpq2,         2},
    {"pinvgamma",       actuar_do_dpq2,         3},
    {"qinvgamma",       actuar_do_dpq2,         4},
    {"minvgamma",       actuar_do_dpq2,         5},
    {"dinvparalogis",   actuar_do_dpq2,         6},
    {"pinvparalogis",   actuar_do_dpq2,         7},
    {"qinvparalogis",   actuar_do_dpq2,         8},
    {"minvparalogis",   actuar_do_dpq2,         9},
    {"dinvpareto",      actuar_do_dpq2,        10},
    {"pinvpareto",      actuar_do_dpq2,        11},
    {"qinvpareto",      actuar_do_dpq2,        12},
    {"minvpareto",      actuar_do_dpq2,        13},
    {"dinvweibull",     actuar_do_dpq2,        14},
    {"pinvweibull",     actuar_do_dpq2,        15},
    {"qinvweibull",     actuar_do_dpq2,        16},
    {"minvweibull",     actuar_do_dpq2,        17},
    {"dlgamma",         actuar_do_dpq2,        18},
    {"plgamma",         actuar_do_dpq2,        19},
    {"qlgamma",         actuar_do_dpq2,        20},
    {"mlgamma",         actuar_do_dpq2,        21},
    {"dllogis",         actuar_do_dpq2,        22},
    {"pllogis",         actuar_do_dpq2,        23},
    {"qllogis",         actuar_do_dpq2,        24},
    {"mllogis",         actuar_do_dpq2,        25},
    {"mlnorm",          actuar_do_dpq2,        26},
    {"dparalogis",      actuar_do_dpq2,        27},
    {"pparalogis",      actuar_do_dpq2,        28},
    {"qparalogis",      actuar_do_dpq2,        29},
    {"mparalogis",      actuar_do_dpq2,        30},
    {"dpareto",         actuar_do_dpq2,        31},
    {"ppareto",         actuar_do_dpq2,        32},
    {"qpareto",         actuar_do_dpq2,        33},
    {"mpareto",         actuar_do_dpq2,        34},
    {"dpareto1",        actuar_do_dpq2,        35},
    {"ppareto1",        actuar_do_dpq2,        36},
    {"qpareto1",        actuar_do_dpq2,        37},
    {"mpareto1",        actuar_do_dpq2,        38},
    {"mweibull",        actuar_do_dpq2,        39},
    {"levexp",          actuar_do_dpq2,        40},
    {"levinvexp",       actuar_do_dpq2,        41},
    {"mbeta",           actuar_do_dpq2,        42},
    {"mgfgamma",        actuar_do_dpq2,        43},
    {"mgfnorm",         actuar_do_dpq2,        44},
    {"mgfunif",         actuar_do_dpq2,        45},
    {"mgfinvgamma",     actuar_do_dpq2,        46},
    {"mnorm",           actuar_do_dpq2,        47},
    {"mchisq",          actuar_do_dpq2,        48},
    {"mgfchisq",        actuar_do_dpq2,        49},
    /* {"minvGauss",       actuar_do_dpq2,        50}, [defunct v3.0-0] */
    /* {"mgfinvGauss",     actuar_do_dpq2,        51}, [defunct v3.0-0] */
    {"munif",           actuar_do_dpq2,        52},
    {"dgumbel",         actuar_do_dpq2,        53},
    {"pgumbel",         actuar_do_dpq2,        54},
    {"qgumbel",         actuar_do_dpq2,        55},
    {"mgumbel",         actuar_do_dpq2,        56},
    {"mgfgumbel",       actuar_do_dpq2,        57},
    {"dinvgauss",       actuar_do_dpq2,        58},
    {"pinvgauss",       actuar_do_dpq2,        59},
    {"qinvgauss",       actuar_do_dpq2,        60},
    {"minvgauss",       actuar_do_dpq2,        61},
    {"mgfinvgauss",     actuar_do_dpq2,        62},
    {"dztnbinom",       actuar_do_dpq2,        101},
    {"pztnbinom",       actuar_do_dpq2,        102},
    {"qztnbinom",       actuar_do_dpq2,        103},
    {"dztbinom",        actuar_do_dpq2,        104},
    {"pztbinom",        actuar_do_dpq2,        105},
    {"qztbinom",        actuar_do_dpq2,        106},
    {"dzmlogarithmic",  actuar_do_dpq2,        107},
    {"pzmlogarithmic",  actuar_do_dpq2,        108},
    {"qzmlogarithmic",  actuar_do_dpq2,        109},
    {"dzmpois",         actuar_do_dpq2,        110},
    {"pzmpois",         actuar_do_dpq2,        111},
    {"qzmpois",         actuar_do_dpq2,        112},
    {"dzmgeom",         actuar_do_dpq2,        113},
    {"pzmgeom",         actuar_do_dpq2,        114},
    {"qzmgeom",         actuar_do_dpq2,        115},
    {"dpoisinvgauss",   actuar_do_dpq2,        116},
    {"ppoisinvgauss",   actuar_do_dpq2,        117},
    {"qpoisinvgauss",   actuar_do_dpq2,        118},
    /* Three parameter distributions */
    {"dburr",           actuar_do_dpq3,         1},
    {"pburr",           actuar_do_dpq3,         2},
    {"qburr",           actuar_do_dpq3,         3},
    {"mburr",           actuar_do_dpq3,         4},
    {"dgenpareto",      actuar_do_dpq3,         5},
    {"pgenpareto",      actuar_do_dpq3,         6},
    {"qgenpareto",      actuar_do_dpq3,         7},
    {"mgenpareto",      actuar_do_dpq3,         8},
    {"dinvburr",        actuar_do_dpq3,         9},
    {"pinvburr",        actuar_do_dpq3,        10},
    {"qinvburr",        actuar_do_dpq3,        11},
    {"minvburr",        actuar_do_dpq3,        12},
    {"dinvtrgamma",     actuar_do_dpq3,        13},
    {"pinvtrgamma",     actuar_do_dpq3,        14},
    {"qinvtrgamma",     actuar_do_dpq3,        15},
    {"minvtrgamma",     actuar_do_dpq3,        16},
    {"dtrgamma",        actuar_do_dpq3,        17},
    {"ptrgamma",        actuar_do_dpq3,        18},
    {"qtrgamma",        actuar_do_dpq3,        19},
    {"mtrgamma",        actuar_do_dpq3,        20},
    {"levgamma",        actuar_do_dpq3,        21},
    {"levinvgamma",     actuar_do_dpq3,        22},
    {"levinvparalogis", actuar_do_dpq3,        23},
    {"levinvpareto",    actuar_do_dpq3,        24},
    {"levinvweibull",   actuar_do_dpq3,        25},
    {"levlgamma",       actuar_do_dpq3,        26},
    {"levllogis",       actuar_do_dpq3,        27},
    {"levlnorm",        actuar_do_dpq3,        28},
    {"levparalogis",    actuar_do_dpq3,        29},
    {"levpareto",       actuar_do_dpq3,        30},
    {"levpareto1",      actuar_do_dpq3,        31},
    {"levweibull",      actuar_do_dpq3,        32},
    {"levbeta",         actuar_do_dpq3,        33},
    {"levchisq",        actuar_do_dpq3,        34},
    /* {"levinvGauss",     actuar_do_dpq3,        35}, [defunct v3.0-0] */
    {"levunif",         actuar_do_dpq3,        36},
    {"levinvgauss",     actuar_do_dpq3,        37},
    {"dpareto2",        actuar_do_dpq3,        38},
    {"ppareto2",        actuar_do_dpq3,        39},
    {"qpareto2",        actuar_do_dpq3,        40},
    {"mpareto2",        actuar_do_dpq3,        41},
    {"dpareto3",        actuar_do_dpq3,        42},
    {"ppareto3",        actuar_do_dpq3,        43},
    {"qpareto3",        actuar_do_dpq3,        44},
    {"mpareto3",        actuar_do_dpq3,        45},
    {"dzmnbinom",       actuar_do_dpq3,       101},
    {"pzmnbinom",       actuar_do_dpq3,       102},
    {"qzmnbinom",       actuar_do_dpq3,       103},
    {"dzmbinom",        actuar_do_dpq3,       104},
    {"pzmbinom",        actuar_do_dpq3,       105},
    {"qzmbinom",        actuar_do_dpq3,       106},
    /* Four parameter distributions */
    {"dtrbeta",         actuar_do_dpq4,        1},
    {"ptrbeta",         actuar_do_dpq4,        2},
    {"qtrbeta",         actuar_do_dpq4,        3},
    {"mtrbeta",         actuar_do_dpq4,        4},
    {"levburr",         actuar_do_dpq4,        5},
    {"levgenpareto",    actuar_do_dpq4,        6},
    {"levinvburr",      actuar_do_dpq4,        7},
    {"levinvtrgamma",   actuar_do_dpq4,        8},
    {"levtrgamma",      actuar_do_dpq4,        9},
    {"dgenbeta",        actuar_do_dpq4,        10},
    {"pgenbeta",        actuar_do_dpq4,        11},
    {"qgenbeta",        actuar_do_dpq4,        12},
    {"mgenbeta",        actuar_do_dpq4,        13},
    {"levpareto2",      actuar_do_dpq4,        14},
    {"levpareto3",      actuar_do_dpq4,        15},
    {"dpareto4",        actuar_do_dpq4,        16},
    {"ppareto4",        actuar_do_dpq4,        17},
    {"qpareto4",        actuar_do_dpq4,        18},
    {"mpareto4",        actuar_do_dpq4,        19},
    /* Five parameter distributions */
    {"levtrbeta",       actuar_do_dpq5,        1},
    {"levgenbeta",      actuar_do_dpq5,        2},
    {"dfpareto",        actuar_do_dpq5,        3},
    {"pfpareto",        actuar_do_dpq5,        4},
    {"qfpareto",        actuar_do_dpq5,        5},
    {"mfpareto",        actuar_do_dpq5,        6},
    {"levpareto4",      actuar_do_dpq5,        7},
    /* Six parameter distributions */
    {"levfpareto",      actuar_do_dpq6,        1},
    /* Phase-type distributions */
    {"dphtype",         actuar_do_dpqphtype2,  1},
    {"pphtype",         actuar_do_dpqphtype2,  2},
    {"mphtype",         actuar_do_dpqphtype2,  3},
    {"mgfphtype",       actuar_do_dpqphtype2,  4},
    {0, 0, 0}
};

/* RANDOM NUMBERS FUNCTIONS */
random_tab_struct random_tab[] = {
    /* One parameter distributions */
    {"rinvexp",         actuar_do_random1,     1, REALSXP},
    {"rlogarithmic",    actuar_do_random1,   101, INTSXP},
    {"rztpois",         actuar_do_random1,   102, INTSXP},
    {"rztgeom",         actuar_do_random1,   103, INTSXP},
    /* Two parameter distributions */
    {"rinvgamma",       actuar_do_random2,     1, REALSXP},
    {"rinvparalogis",   actuar_do_random2,     2, REALSXP},
    {"rinvpareto",      actuar_do_random2,     3, REALSXP},
    {"rinvweibull",     actuar_do_random2,     4, REALSXP},
    {"rlgamma",         actuar_do_random2,     5, REALSXP},
    {"rllogis",         actuar_do_random2,     6, REALSXP},
    {"rparalogis",      actuar_do_random2,     7, REALSXP},
    {"rpareto",         actuar_do_random2,     8, REALSXP},
    {"rpareto1",        actuar_do_random2,     9, REALSXP},
    {"rgumbel",         actuar_do_random2,    10, REALSXP},
    {"rinvgauss",       actuar_do_random2,    11, REALSXP},
    {"rztnbinom",       actuar_do_random2,   101, INTSXP},
    {"rztbinom",        actuar_do_random2,   102, INTSXP},
    {"rzmlogarithmic",  actuar_do_random2,   103, INTSXP},
    {"rzmpois",         actuar_do_random2,   104, INTSXP},
    {"rzmgeom",         actuar_do_random2,   105, INTSXP},
    {"rpoisinvgauss",   actuar_do_random2,   106, INTSXP},
    /* Three parameter distributions */
    {"rburr",           actuar_do_random3,     1, REALSXP},
    {"rgenpareto",      actuar_do_random3,     2, REALSXP},
    {"rinvburr",        actuar_do_random3,     3, REALSXP},
    {"rinvtrgamma",     actuar_do_random3,     4, REALSXP},
    {"rtrgamma",        actuar_do_random3,     5, REALSXP},
    {"rpareto2",        actuar_do_random3,     6, REALSXP},
    {"rpareto3",        actuar_do_random3,     7, REALSXP},
    {"rzmnbinom",       actuar_do_random3,   101, INTSXP},
    {"rzmbinom",        actuar_do_random3,   102, INTSXP},
    /* Four parameter distributions */
    {"rtrbeta",         actuar_do_random4,     1, REALSXP},
    {"rgenbeta",        actuar_do_random4,     2, REALSXP},
    {"rpareto4",        actuar_do_random4,     3, REALSXP},
    /* Five parameter distributions */
    {"rfpareto",        actuar_do_random5,     1, REALSXP},
    /* Phase-type distributions */
    {"rphtype",         actuar_do_randomphtype2, 1, REALSXP},
    {0, 0, 0}
};