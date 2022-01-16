// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "vector2.h"
#include "vector3.h"

#define STR(s) #s

namespace vox {

const Vector2D kSamplePoints2[] = {
    {0.345361, 0.379616},
    {0.689684, 0.981134},
    {0.178295, 0.775100},
    {0.016982, 0.948684},
    {0.716177, 0.657466},
    {0.392409, 0.098665},
    {0.059524, 0.088721},
    {0.567570, 0.352076},
    {0.047863, 0.901897},
    {0.712245, 0.502281},
    {0.437343, 0.607144},
    {0.109745, 0.621235},
    {0.096203, 0.365931},
    {0.842683, 0.418980},
    {0.751143, 0.166908},
    {0.124889, 0.026507},
    {0.663767, 0.196349},
    {0.656994, 0.257587},
    {0.283738, 0.442652},
    {0.421362, 0.263528},
    {0.889199, 0.812583},
    {0.513579, 0.882426},
    {0.116088, 0.187651},
    {0.408908, 0.540011},
    {0.479765, 0.427906},
    {0.916287, 0.699123},
    {0.810567, 0.455548},
    {0.633501, 0.722117},
    {0.869039, 0.879401},
    {0.634359, 0.656880},
    {0.881239, 0.928651},
    {0.192255, 0.782989},
    {0.143437, 0.040834},
    {0.811243, 0.580179},
    {0.323126, 0.347108},
    {0.821038, 0.591176},
    {0.874554, 0.746953},
    {0.747251, 0.493964},
    {0.698499, 0.790584},
    {0.451200, 0.175852},
    {0.394435, 0.170139},
    {0.575606, 0.139201},
    {0.519766, 0.637931},
    {0.897444, 0.818441},
    {0.660771, 0.763253},
    {0.210160, 0.702209},
    {0.411656, 0.338267},
    {0.560503, 0.445439},
    {0.669966, 0.767095},
    {0.687153, 0.991888},
    {0.215029, 0.115820},
    {0.666109, 0.881175},
    {0.122334, 0.603771},
    {0.275602, 0.970806},
    {0.572030, 0.277108},
    {0.666184, 0.761624},
    {0.184890, 0.685102},
    {0.196658, 0.770965},
    {0.652366, 0.135286},
    {0.416088, 0.773534},
    {0.350510, 0.739229},
    {0.602128, 0.603852},
    {0.932349, 0.114926},
    {0.109750, 0.507729},
    {0.305887, 0.921879},
    {0.373499, 0.295627},
    {0.948411, 0.127778},
    {0.997719, 0.308245},
    {0.939498, 0.884958},
    {0.958866, 0.208753},
    {0.658005, 0.811717},
    {0.337530, 0.183797},
    {0.102327, 0.600194},
    {0.252880, 0.466689},
    {0.024216, 0.013599},
    {0.712552, 0.134843},
    {0.135397, 0.302475},
    {0.312750, 0.598819},
    {0.852396, 0.657736},
    {0.942883, 0.155169},
    {0.021386, 0.650356},
    {0.440839, 0.593921},
    {0.524037, 0.412471},
    {0.953303, 0.404403},
    {0.706313, 0.116943},
    {0.986237, 0.273937},
    {0.463267, 0.861108},
    {0.441331, 0.039794},
    {0.816625, 0.360040},
    {0.612656, 0.117950},
    {0.971704, 0.547998},
    {0.425068, 0.915426},
    {0.242974, 0.237278},
    {0.184436, 0.911548},
    {0.847674, 0.444267},
    {0.003595, 0.302114},
    {0.448335, 0.006152},
    {0.417010, 0.954228},
    {0.465312, 0.154684},
    {0.797367, 0.573884}
};

const Vector2D kSampleDirs2[] = {
    {-0.834837, -0.550497},
    {-0.631745, 0.775177},
    {-0.123673, -0.992323},
    {0.461529, 0.887125},
    {0.827792, 0.561035},
    {0.099221, -0.995065},
    {0.362386, -0.932028},
    {-0.943357, 0.331780},
    {0.125962, -0.992035},
    {-0.611567, 0.791193},
    {0.783917, -0.620866},
    {0.928452, -0.371452},
    {0.999132, -0.041662},
    {0.988302, 0.152510},
    {0.164164, -0.986433},
    {1.000000, 0.000606},
    {-0.864073, -0.503367},
    {-0.234965, -0.972004},
    {0.830583, -0.556895},
    {0.847955, 0.530068},
    {0.984571, 0.174987},
    {-0.464266, 0.885696},
    {0.201224, -0.979545},
    {0.883430, 0.468563},
    {0.900634, 0.434578},
    {-0.958385, -0.285481},
    {-0.839971, 0.542632},
    {0.973045, -0.230616},
    {-0.859217, -0.511611},
    {0.990658, 0.136368},
    {0.060143, 0.998190},
    {0.087498, -0.996165},
    {0.998413, 0.056323},
    {0.393290, 0.919414},
    {0.750650, 0.660700},
    {0.711934, -0.702246},
    {0.987396, -0.158268},
    {-0.961487, 0.274851},
    {0.960084, 0.279713},
    {0.842703, 0.538379},
    {0.291245, -0.956649},
    {0.653652, -0.756795},
    {0.805878, 0.592082},
    {0.194257, -0.980951},
    {0.114234, -0.993454},
    {-0.621933, 0.783071},
    {-0.993070, -0.117521},
    {0.991110, 0.133047},
    {0.991560, -0.129646},
    {-0.901704, -0.432355},
    {0.959840, 0.280549},
    {0.809570, -0.587024},
    {-0.512569, 0.858646},
    {0.990664, -0.136327},
    {0.695819, -0.718217},
    {-0.878328, 0.478059},
    {0.907827, -0.419344},
    {0.696731, 0.717333},
    {-0.730065, -0.683378},
    {-0.608621, 0.793461},
    {-0.985353, -0.170529},
    {0.785365, -0.619033},
    {-0.656787, -0.754076},
    {-0.596506, -0.802609},
    {-0.651835, -0.758361},
    {0.723279, -0.690556},
    {0.589656, 0.807655},
    {0.724230, 0.689559},
    {0.933769, -0.357876},
    {0.999843, -0.017728},
    {-0.540588, 0.841287},
    {-0.766218, -0.642581},
    {-0.262458, 0.964943},
    {-0.934809, -0.355152},
    {-0.446191, -0.894938},
    {0.986583, -0.163262},
    {-0.995628, 0.093407},
    {0.050012, -0.998749},
    {-0.494582, 0.869131},
    {0.682014, 0.731339},
    {0.834163, 0.551518},
    {0.554322, 0.832302},
    {0.878926, 0.476958},
    {-0.748926, 0.662654},
    {-0.578204, -0.815892},
    {0.413582, -0.910467},
    {0.460255, -0.887787},
    {-0.664631, 0.747172},
    {0.561924, -0.827189},
    {-0.957942, -0.286962},
    {0.486858, 0.873481},
    {-0.710029, -0.704172},
    {0.706389, -0.707823},
    {0.371374, 0.928483},
    {0.552099, 0.833779},
    {0.221655, -0.975125},
    {-0.938927, -0.344118},
    {0.421843, 0.906669},
    {0.520394, 0.853926},
    {0.817585, -0.575807}
};

const Vector3D kSamplePoints3[] = {
    {0.497400, 0.340319, 0.174018},
    {0.345847, 0.671895, 0.770077},
    {0.824750, 0.832587, 0.337455},
    {0.788730, 0.938434, 0.392927},
    {0.262384, 0.063295, 0.481592},
    {0.137059, 0.340083, 0.780170},
    {0.410246, 0.356760, 0.271641},
    {0.258869, 0.499761, 0.714568},
    {0.960643, 0.896457, 0.744053},
    {0.969492, 0.620965, 0.038201},
    {0.761103, 0.067140, 0.003153},
    {0.808669, 0.349383, 0.602196},
    {0.527798, 0.200637, 0.277750},
    {0.820000, 0.267404, 0.210669},
    {0.871385, 0.384953, 0.585981},
    {0.259116, 0.575521, 0.736410},
    {0.961039, 0.137049, 0.688318},
    {0.652596, 0.305719, 0.874114},
    {0.432216, 0.886638, 0.919146},
    {0.105440, 0.652642, 0.061559},
    {0.639214, 0.008707, 0.344644},
    {0.506621, 0.104165, 0.560967},
    {0.055950, 0.595481, 0.611841},
    {0.726020, 0.888253, 0.439209},
    {0.977397, 0.353103, 0.486040},
    {0.321141, 0.496627, 0.490141},
    {0.660194, 0.271911, 0.568495},
    {0.121249, 0.848909, 0.466652},
    {0.578311, 0.334937, 0.663786},
    {0.026048, 0.787703, 0.257295},
    {0.441405, 0.713241, 0.438669},
    {0.425619, 0.940345, 0.376602},
    {0.580785, 0.905464, 0.504882},
    {0.497568, 0.670469, 0.330681},
    {0.854962, 0.030817, 0.229460},
    {0.339229, 0.397792, 0.845276},
    {0.392889, 0.403645, 0.110404},
    {0.048508, 0.554204, 0.010991},
    {0.668386, 0.806681, 0.106063},
    {0.473332, 0.897396, 0.369129},
    {0.879946, 0.464546, 0.095410},
    {0.828294, 0.537904, 0.273714},
    {0.269106, 0.978606, 0.868892},
    {0.195268, 0.492400, 0.244056},
    {0.576959, 0.525732, 0.304788},
    {0.410733, 0.051802, 0.789971},
    {0.966585, 0.403823, 0.595742},
    {0.680305, 0.193207, 0.723708},
    {0.374682, 0.211646, 0.298336},
    {0.693784, 0.752065, 0.610412},
    {0.444658, 0.311000, 0.632398},
    {0.605686, 0.327283, 0.651981},
    {0.358708, 0.327774, 0.529254},
    {0.591066, 0.774619, 0.266842},
    {0.632197, 0.057545, 0.470357},
    {0.415280, 0.390888, 0.708106},
    {0.686436, 0.119143, 0.151267},
    {0.864336, 0.801096, 0.176234},
    {0.508921, 0.976984, 0.812028},
    {0.815223, 0.787772, 0.840940},
    {0.270436, 0.259103, 0.457229},
    {0.741541, 0.705125, 0.506695},
    {0.050869, 0.454618, 0.022979},
    {0.647166, 0.745158, 0.667532},
    {0.647613, 0.198647, 0.527858},
    {0.550523, 0.772316, 0.833556},
    {0.618357, 0.948876, 0.612774},
    {0.888236, 0.461945, 0.630564},
    {0.581529, 0.987256, 0.897477},
    {0.198041, 0.650353, 0.740811},
    {0.000253, 0.826019, 0.809284},
    {0.277294, 0.922714, 0.159235},
    {0.125245, 0.394914, 0.185451},
    {0.182339, 0.864938, 0.677111},
    {0.541744, 0.046790, 0.287032},
    {0.517508, 0.242606, 0.832993},
    {0.722396, 0.721982, 0.912246},
    {0.357276, 0.301075, 0.673499},
    {0.857920, 0.308104, 0.233233},
    {0.508702, 0.362859, 0.591321},
    {0.790020, 0.247796, 0.197567},
    {0.058633, 0.506554, 0.313645},
    {0.643169, 0.001582, 0.970613},
    {0.680016, 0.227724, 0.966055},
    {0.212052, 0.785980, 0.525420},
    {0.622927, 0.092216, 0.435965},
    {0.429010, 0.640716, 0.324353},
    {0.566219, 0.495695, 0.501004},
    {0.626306, 0.880628, 0.806723},
    {0.038548, 0.027644, 0.773834},
    {0.455215, 0.959835, 0.236123},
    {0.533056, 0.965158, 0.634343},
    {0.124713, 0.273837, 0.727391},
    {0.570217, 0.877730, 0.037296},
    {0.512131, 0.545868, 0.174878},
    {0.162331, 0.733906, 0.043851},
    {0.004506, 0.551064, 0.173766},
    {0.179539, 0.639458, 0.214501},
    {0.623272, 0.857292, 0.387644},
    {0.840032, 0.338341, 0.155947}
};

const Vector3D kSampleDirs3[] = {
    {-0.412626, 0.346615, 0.842376},
    {-0.159642, 0.702771, 0.693273},
    {0.626628, -0.656825, 0.419426},
    {0.546020, 0.709740, -0.445119},
    {0.463970, 0.711729, -0.527422},
    {-0.799261, -0.286253, -0.528434},
    {-0.426917, 0.737267, 0.523621},
    {-0.519358, 0.430140, -0.738408},
    {0.293382, 0.754417, -0.587181},
    {0.187069, 0.875009, -0.446503},
    {0.135364, -0.358041, 0.923841},
    {0.696725, 0.472670, -0.539590},
    {0.725969, 0.016815, -0.687522},
    {0.586766, 0.732091, -0.346047},
    {0.594526, -0.801264, 0.067189},
    {-0.135026, -0.485966, 0.863484},
    {-0.900620, 0.252128, -0.354000},
    {-0.651495, -0.561726, 0.509920},
    {0.631380, -0.461119, -0.623481},
    {0.668953, -0.657534, 0.346628},
    {-0.075516, -0.645187, 0.760284},
    {-0.554764, -0.370377, 0.745022},
    {-0.649783, 0.586463, -0.483573},
    {-0.817992, -0.158249, 0.553034},
    {-0.723074, 0.545119, -0.424276},
    {-0.183442, -0.551459, -0.813782},
    {-0.382321, -0.769024, 0.512281},
    {0.282039, -0.608147, 0.742032},
    {0.960025, -0.114449, -0.255446},
    {-0.284570, -0.916490, 0.281186},
    {-0.589486, 0.619899, 0.517911},
    {0.142000, -0.863406, 0.484114},
    {0.091577, -0.134608, 0.986658},
    {0.509412, -0.201465, -0.836607},
    {0.083146, 0.978916, 0.186573},
    {0.625844, -0.659236, 0.416806},
    {0.872060, -0.448630, -0.195556},
    {-0.999112, -0.042136, 0.000060},
    {-0.170327, 0.198389, 0.965210},
    {0.937792, -0.137543, 0.318792},
    {0.245423, -0.061242, 0.967480},
    {0.233324, -0.322487, 0.917367},
    {-0.055309, -0.740711, 0.669543},
    {-0.647869, -0.379706, 0.660371},
    {-0.667515, -0.694258, 0.269128},
    {0.115134, -0.736097, -0.667013},
    {0.365225, 0.707066, 0.605531},
    {-0.761231, -0.511205, -0.398994},
    {-0.668287, 0.455066, -0.588479},
    {-0.238968, 0.937489, 0.252999},
    {0.621444, 0.780138, 0.072056},
    {0.228231, 0.819871, -0.525092},
    {0.523007, -0.375250, -0.765279},
    {-0.924150, 0.178367, 0.337834},
    {0.339832, 0.510140, -0.790108},
    {0.601994, -0.208286, -0.770857},
    {0.316481, -0.918083, -0.238671},
    {0.777566, 0.015384, -0.628613},
    {0.275787, 0.957493, 0.084555},
    {-0.474831, -0.487453, 0.732752},
    {0.974242, -0.002691, 0.225489},
    {0.856188, 0.510533, -0.079366},
    {0.097690, 0.777224, 0.621595},
    {0.228268, -0.818331, -0.527473},
    {0.056570, 0.950774, -0.304678},
    {-0.579401, 0.771526, 0.262760},
    {-0.456913, 0.271317, -0.847123},
    {0.654652, -0.755685, -0.019258},
    {0.749825, 0.638450, 0.173622},
    {0.919134, 0.153333, -0.362879},
    {-0.059068, -0.063108, 0.996257},
    {0.637013, -0.761346, 0.120692},
    {-0.971146, -0.235058, -0.040281},
    {-0.887387, -0.379031, -0.262451},
    {-0.321031, -0.381300, 0.866920},
    {0.728688, -0.259951, -0.633592},
    {0.320396, -0.743341, 0.587188},
    {0.578361, 0.450433, -0.680153},
    {0.877732, 0.402931, 0.259295},
    {0.478574, 0.850736, 0.217292},
    {0.527917, 0.234938, -0.816154},
    {0.504137, 0.322646, 0.801090},
    {-0.586146, -0.620019, 0.521546},
    {0.677291, -0.420016, 0.604039},
    {-0.979604, 0.200903, -0.003732},
    {-0.682363, -0.184902, 0.707242},
    {-0.829199, 0.105079, 0.548988},
    {-0.525318, 0.785402, 0.327391},
    {-0.056204, -0.615759, -0.785927},
    {0.787225, 0.521508, -0.329099},
    {0.608854, -0.741327, 0.282369},
    {-0.675777, -0.671399, -0.304219},
    {0.533726, 0.677636, 0.505912},
    {-0.584978, 0.198362, 0.786418},
    {0.151476, -0.896765, -0.415774},
    {-0.562947, -0.770364, 0.299381},
    {-0.407004, -0.795582, 0.448773},
    {0.567580, 0.114354, 0.815338},
    {0.624382, -0.591191, 0.510530},
    {0.769309, -0.608519, 0.194597}
};

const char* kCubeTriMesh3x3x3AsObj = STR(
    v -0.500000 -0.500000 0.500000\n
    v -0.166667 -0.500000 0.500000\n
    v 0.166667 -0.500000 0.500000\n
    v 0.500000 -0.500000 0.500000\n
    v -0.500000 -0.166667 0.500000\n
    v -0.166667 -0.166667 0.500000\n
    v 0.166667 -0.166667 0.500000\n
    v 0.500000 -0.166667 0.500000\n
    v -0.500000 0.166667 0.500000\n
    v -0.166667 0.166667 0.500000\n
    v 0.166667 0.166667 0.500000\n
    v 0.500000 0.166667 0.500000\n
    v -0.500000 0.500000 0.500000\n
    v -0.166667 0.500000 0.500000\n
    v 0.166667 0.500000 0.500000\n
    v 0.500000 0.500000 0.500000\n
    v -0.500000 0.500000 0.166667\n
    v -0.166667 0.500000 0.166667\n
    v 0.166667 0.500000 0.166667\n
    v 0.500000 0.500000 0.166667\n
    v -0.500000 0.500000 -0.166667\n
    v -0.166667 0.500000 -0.166667\n
    v 0.166667 0.500000 -0.166667\n
    v 0.500000 0.500000 -0.166667\n
    v -0.500000 0.500000 -0.500000\n
    v -0.166667 0.500000 -0.500000\n
    v 0.166667 0.500000 -0.500000\n
    v 0.500000 0.500000 -0.500000\n
    v -0.500000 0.166667 -0.500000\n
    v -0.166667 0.166667 -0.500000\n
    v 0.166667 0.166667 -0.500000\n
    v 0.500000 0.166667 -0.500000\n
    v -0.500000 -0.166667 -0.500000\n
    v -0.166667 -0.166667 -0.500000\n
    v 0.166667 -0.166667 -0.500000\n
    v 0.500000 -0.166667 -0.500000\n
    v -0.500000 -0.500000 -0.500000\n
    v -0.166667 -0.500000 -0.500000\n
    v 0.166667 -0.500000 -0.500000\n
    v 0.500000 -0.500000 -0.500000\n
    v -0.500000 -0.500000 -0.166667\n
    v -0.166667 -0.500000 -0.166667\n
    v 0.166667 -0.500000 -0.166667\n
    v 0.500000 -0.500000 -0.166667\n
    v -0.500000 -0.500000 0.166667\n
    v -0.166667 -0.500000 0.166667\n
    v 0.166667 -0.500000 0.166667\n
    v 0.500000 -0.500000 0.166667\n
    v 0.500000 -0.166667 -0.166667\n
    v 0.500000 -0.166667 0.166667\n
    v 0.500000 0.166667 -0.166667\n
    v 0.500000 0.166667 0.166667\n
    v -0.500000 -0.166667 -0.166667\n
    v -0.500000 -0.166667 0.166667\n
    v -0.500000 0.166667 -0.166667\n
    v -0.500000 0.166667 0.166667\n
    vt 0.375000 0.000000\n
    vt 0.458333 0.000000\n
    vt 0.541667 0.000000\n
    vt 0.625000 0.000000\n
    vt 0.375000 0.083333\n
    vt 0.458333 0.083333\n
    vt 0.541667 0.083333\n
    vt 0.625000 0.083333\n
    vt 0.375000 0.166667\n
    vt 0.458333 0.166667\n
    vt 0.541667 0.166667\n
    vt 0.625000 0.166667\n
    vt 0.375000 0.250000\n
    vt 0.458333 0.250000\n
    vt 0.541667 0.250000\n
    vt 0.625000 0.250000\n
    vt 0.375000 0.333333\n
    vt 0.458333 0.333333\n
    vt 0.541667 0.333333\n
    vt 0.625000 0.333333\n
    vt 0.375000 0.416667\n
    vt 0.458333 0.416667\n
    vt 0.541667 0.416667\n
    vt 0.625000 0.416667\n
    vt 0.375000 0.500000\n
    vt 0.458333 0.500000\n
    vt 0.541667 0.500000\n
    vt 0.625000 0.500000\n
    vt 0.375000 0.583333\n
    vt 0.458333 0.583333\n
    vt 0.541667 0.583333\n
    vt 0.625000 0.583333\n
    vt 0.375000 0.666667\n
    vt 0.458333 0.666667\n
    vt 0.541667 0.666667\n
    vt 0.625000 0.666667\n
    vt 0.375000 0.750000\n
    vt 0.458333 0.750000\n
    vt 0.541667 0.750000\n
    vt 0.625000 0.750000\n
    vt 0.375000 0.833333\n
    vt 0.458333 0.833333\n
    vt 0.541667 0.833333\n
    vt 0.625000 0.833333\n
    vt 0.375000 0.916667\n
    vt 0.458333 0.916667\n
    vt 0.541667 0.916667\n
    vt 0.625000 0.916667\n
    vt 0.375000 1.000000\n
    vt 0.458333 1.000000\n
    vt 0.541667 1.000000\n
    vt 0.625000 1.000000\n
    vt 0.875000 0.000000\n
    vt 0.791667 0.000000\n
    vt 0.708333 0.000000\n
    vt 0.875000 0.083333\n
    vt 0.791667 0.083333\n
    vt 0.708333 0.083333\n
    vt 0.875000 0.166667\n
    vt 0.791667 0.166667\n
    vt 0.708333 0.166667\n
    vt 0.875000 0.250000\n
    vt 0.791667 0.250000\n
    vt 0.708333 0.250000\n
    vt 0.125000 0.000000\n
    vt 0.208333 0.000000\n
    vt 0.291667 0.000000\n
    vt 0.125000 0.083333\n
    vt 0.208333 0.083333\n
    vt 0.291667 0.083333\n
    vt 0.125000 0.166667\n
    vt 0.208333 0.166667\n
    vt 0.291667 0.166667\n
    vt 0.125000 0.250000\n
    vt 0.208333 0.250000\n
    vt 0.291667 0.250000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 0.000000 1.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 1.000000 0.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 0.000000 -1.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 0.000000 -1.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn 1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    vn -1.000000 0.000000 0.000000\n
    f 1/1/1 2/2/2 5/5/3\n
    f 5/5/3 2/2/2 6/6/4\n
    f 2/2/2 3/3/5 6/6/4\n
    f 6/6/4 3/3/5 7/7/6\n
    f 3/3/5 4/4/7 7/7/6\n
    f 7/7/6 4/4/7 8/8/8\n
    f 5/5/3 6/6/4 9/9/9\n
    f 9/9/9 6/6/4 10/10/10\n
    f 6/6/4 7/7/6 10/10/10\n
    f 10/10/10 7/7/6 11/11/11\n
    f 7/7/6 8/8/8 11/11/11\n
    f 11/11/11 8/8/8 12/12/12\n
    f 9/9/9 10/10/10 13/13/13\n
    f 13/13/13 10/10/10 14/14/14\n
    f 10/10/10 11/11/11 14/14/14\n
    f 14/14/14 11/11/11 15/15/15\n
    f 11/11/11 12/12/12 15/15/15\n
    f 15/15/15 12/12/12 16/16/16\n
    f 13/13/17 14/14/18 17/17/19\n
    f 17/17/19 14/14/18 18/18/20\n
    f 14/14/18 15/15/21 18/18/20\n
    f 18/18/20 15/15/21 19/19/22\n
    f 15/15/21 16/16/23 19/19/22\n
    f 19/19/22 16/16/23 20/20/24\n
    f 17/17/19 18/18/20 21/21/25\n
    f 21/21/25 18/18/20 22/22/26\n
    f 18/18/20 19/19/22 22/22/26\n
    f 22/22/26 19/19/22 23/23/27\n
    f 19/19/22 20/20/24 23/23/27\n
    f 23/23/27 20/20/24 24/24/28\n
    f 21/21/25 22/22/26 25/25/29\n
    f 25/25/29 22/22/26 26/26/30\n
    f 22/22/26 23/23/27 26/26/30\n
    f 26/26/30 23/23/27 27/27/31\n
    f 23/23/27 24/24/28 27/27/31\n
    f 27/27/31 24/24/28 28/28/32\n
    f 25/25/33 26/26/34 29/29/35\n
    f 29/29/35 26/26/34 30/30/36\n
    f 26/26/34 27/27/37 30/30/36\n
    f 30/30/36 27/27/37 31/31/38\n
    f 27/27/37 28/28/39 31/31/38\n
    f 31/31/38 28/28/39 32/32/40\n
    f 29/29/35 30/30/36 33/33/41\n
    f 33/33/41 30/30/36 34/34/42\n
    f 30/30/36 31/31/38 34/34/42\n
    f 34/34/42 31/31/38 35/35/43\n
    f 31/31/38 32/32/40 35/35/43\n
    f 35/35/43 32/32/40 36/36/44\n
    f 33/33/41 34/34/42 37/37/45\n
    f 37/37/45 34/34/42 38/38/46\n
    f 34/34/42 35/35/43 38/38/46\n
    f 38/38/46 35/35/43 39/39/47\n
    f 35/35/43 36/36/44 39/39/47\n
    f 39/39/47 36/36/44 40/40/48\n
    f 37/37/49 38/38/50 41/41/51\n
    f 41/41/51 38/38/50 42/42/52\n
    f 38/38/50 39/39/53 42/42/52\n
    f 42/42/52 39/39/53 43/43/54\n
    f 39/39/53 40/40/55 43/43/54\n
    f 43/43/54 40/40/55 44/44/56\n
    f 41/41/51 42/42/52 45/45/57\n
    f 45/45/57 42/42/52 46/46/58\n
    f 42/42/52 43/43/54 46/46/58\n
    f 46/46/58 43/43/54 47/47/59\n
    f 43/43/54 44/44/56 47/47/59\n
    f 47/47/59 44/44/56 48/48/60\n
    f 45/45/57 46/46/58 1/49/61\n
    f 1/49/61 46/46/58 2/50/62\n
    f 46/46/58 47/47/59 2/50/62\n
    f 2/50/62 47/47/59 3/51/63\n
    f 47/47/59 48/48/60 3/51/63\n
    f 3/51/63 48/48/60 4/52/64\n
    f 44/54/65 40/53/66 49/57/67\n
    f 49/57/67 40/53/66 36/56/68\n
    f 48/55/69 44/54/65 50/58/70\n
    f 50/58/70 44/54/65 49/57/67\n
    f 4/4/71 48/55/69 8/8/72\n
    f 8/8/72 48/55/69 50/58/70\n
    f 49/57/67 36/56/68 51/60/73\n
    f 51/60/73 36/56/68 32/59/74\n
    f 50/58/70 49/57/67 52/61/75\n
    f 52/61/75 49/57/67 51/60/73\n
    f 8/8/72 50/58/70 12/12/76\n
    f 12/12/76 50/58/70 52/61/75\n
    f 51/60/73 32/59/74 24/63/77\n
    f 24/63/77 32/59/74 28/62/78\n
    f 52/61/75 51/60/73 20/64/79\n
    f 20/64/79 51/60/73 24/63/77\n
    f 12/12/76 52/61/75 16/16/80\n
    f 16/16/80 52/61/75 20/64/79\n
    f 37/65/81 41/66/82 33/68/83\n
    f 33/68/83 41/66/82 53/69/84\n
    f 41/66/82 45/67/85 53/69/84\n
    f 53/69/84 45/67/85 54/70/86\n
    f 45/67/85 1/1/87 54/70/86\n
    f 54/70/86 1/1/87 5/5/88\n
    f 33/68/83 53/69/84 29/71/89\n
    f 29/71/89 53/69/84 55/72/90\n
    f 53/69/84 54/70/86 55/72/90\n
    f 55/72/90 54/70/86 56/73/91\n
    f 54/70/86 5/5/88 56/73/91\n
    f 56/73/91 5/5/88 9/9/92\n
    f 29/71/89 55/72/90 25/74/93\n
    f 25/74/93 55/72/90 21/75/94\n
    f 55/72/90 56/73/91 21/75/94\n
    f 21/75/94 56/73/91 17/76/95\n
    f 56/73/91 9/9/92 17/76/95\n
    f 17/76/95 9/9/92 13/13/96);

const char* kSphereTriMesh5x5Obj = STR(
    v 0.090818 -0.404509 -0.279509\n
    v -0.237764 -0.404509 -0.172746\n
    v -0.237764 -0.404509 0.172746\n
    v 0.090818 -0.404509 0.279509\n
    v 0.293893 -0.404509 0.000000\n
    v 0.146946 -0.154508 -0.452254\n
    v -0.384710 -0.154508 -0.279509\n
    v -0.384710 -0.154508 0.279509\n
    v 0.146946 -0.154508 0.452254\n
    v 0.475528 -0.154508 0.000000\n
    v 0.146946 0.154508 -0.452254\n
    v -0.384710 0.154508 -0.279509\n
    v -0.384710 0.154508 0.279509\n
    v 0.146946 0.154508 0.452254\n
    v 0.475528 0.154508 0.000000\n
    v 0.090818 0.404509 -0.279509\n
    v -0.237764 0.404509 -0.172746\n
    v -0.237764 0.404509 0.172746\n
    v 0.090818 0.404509 0.279509\n
    v 0.293893 0.404509 0.000000\n
    v 0.000000 -0.500000 0.000000\n
    v 0.000000 0.500000 0.000000\n
    vt 0.000000 0.200000\n
    vt 0.200000 0.200000\n
    vt 0.400000 0.200000\n
    vt 0.600000 0.200000\n
    vt 0.800000 0.200000\n
    vt 1.000000 0.200000\n
    vt 0.000000 0.400000\n
    vt 0.200000 0.400000\n
    vt 0.400000 0.400000\n
    vt 0.600000 0.400000\n
    vt 0.800000 0.400000\n
    vt 1.000000 0.400000\n
    vt 0.000000 0.600000\n
    vt 0.200000 0.600000\n
    vt 0.400000 0.600000\n
    vt 0.600000 0.600000\n
    vt 0.800000 0.600000\n
    vt 1.000000 0.600000\n
    vt 0.000000 0.800000\n
    vt 0.200000 0.800000\n
    vt 0.400000 0.800000\n
    vt 0.600000 0.800000\n
    vt 0.800000 0.800000\n
    vt 1.000000 0.800000\n
    vt 0.100000 0.000000\n
    vt 0.300000 0.000000\n
    vt 0.500000 0.000000\n
    vt 0.700000 0.000000\n
    vt 0.900000 0.000000\n
    vt 0.100000 1.000000\n
    vt 0.300000 1.000000\n
    vt 0.500000 1.000000\n
    vt 0.700000 1.000000\n
    vt 0.900000 1.000000\n
    vn 0.302285 -0.776168 -0.553342\n
    vn -0.432849 -0.776168 -0.458482\n
    vn 0.309013 -0.318771 -0.896045\n
    vn -0.756699 -0.318771 -0.570782\n
    vn -0.432849 -0.776168 -0.458482\n
    vn -0.569800 -0.776168 0.269985\n
    vn -0.756699 -0.318771 -0.570782\n
    vn -0.776679 -0.318771 0.543282\n
    vn -0.569800 -0.776168 0.269985\n
    vn 0.080693 -0.776168 0.625342\n
    vn -0.776679 -0.318771 0.543282\n
    vn 0.276685 -0.318771 0.906549\n
    vn 0.080693 -0.776168 0.625342\n
    vn 0.619671 -0.776168 0.116498\n
    vn 0.276685 -0.318771 0.906549\n
    vn 0.947680 -0.318771 0.016996\n
    vn 0.619671 -0.776168 0.116498\n
    vn 0.302285 -0.776168 -0.553342\n
    vn 0.947680 -0.318771 0.016996\n
    vn 0.309013 -0.318771 -0.896045\n
    vn 0.309013 -0.318771 -0.896045\n
    vn -0.756699 -0.318771 -0.570782\n
    vn 0.276685 0.318771 -0.906549\n
    vn -0.776679 0.318771 -0.543282\n
    vn -0.756699 -0.318771 -0.570782\n
    vn -0.776679 -0.318771 0.543282\n
    vn -0.776679 0.318771 -0.543282\n
    vn -0.756699 0.318771 0.570782\n
    vn -0.776679 -0.318771 0.543282\n
    vn 0.276685 -0.318771 0.906549\n
    vn -0.756699 0.318771 0.570782\n
    vn 0.309013 0.318771 0.896045\n
    vn 0.276685 -0.318771 0.906549\n
    vn 0.947680 -0.318771 0.016996\n
    vn 0.309013 0.318771 0.896045\n
    vn 0.947680 0.318771 -0.016996\n
    vn 0.947680 -0.318771 0.016996\n
    vn 0.309013 -0.318771 -0.896045\n
    vn 0.947680 0.318771 -0.016996\n
    vn 0.276685 0.318771 -0.906549\n
    vn 0.276685 0.318771 -0.906549\n
    vn -0.776679 0.318771 -0.543282\n
    vn 0.080693 0.776168 -0.625342\n
    vn -0.569800 0.776168 -0.269985\n
    vn -0.776679 0.318771 -0.543282\n
    vn -0.756699 0.318771 0.570782\n
    vn -0.569800 0.776168 -0.269985\n
    vn -0.432849 0.776168 0.458482\n
    vn -0.756699 0.318771 0.570782\n
    vn 0.309013 0.318771 0.896045\n
    vn -0.432849 0.776168 0.458482\n
    vn 0.302285 0.776168 0.553342\n
    vn 0.309013 0.318771 0.896045\n
    vn 0.947680 0.318771 -0.016996\n
    vn 0.302285 0.776168 0.553342\n
    vn 0.619671 0.776168 -0.116498\n
    vn 0.947680 0.318771 -0.016996\n
    vn 0.276685 0.318771 -0.906549\n
    vn 0.619671 0.776168 -0.116498\n
    vn 0.080693 0.776168 -0.625342\n
    vn -0.432849 -0.776168 -0.458482\n
    vn 0.302285 -0.776168 -0.553342\n
    vn 0.000000 -1.000000 -0.000000\n
    vn -0.569800 -0.776168 0.269985\n
    vn -0.432849 -0.776168 -0.458482\n
    vn 0.000000 -1.000000 -0.000000\n
    vn 0.080693 -0.776168 0.625342\n
    vn -0.569800 -0.776168 0.269985\n
    vn 0.000000 -1.000000 -0.000000\n
    vn 0.619671 -0.776168 0.116498\n
    vn 0.080693 -0.776168 0.625342\n
    vn 0.000000 -1.000000 -0.000000\n
    vn 0.302285 -0.776168 -0.553342\n
    vn 0.619671 -0.776168 0.116498\n
    vn 0.000000 -1.000000 -0.000000\n
    vn 0.080693 0.776168 -0.625342\n
    vn -0.569800 0.776168 -0.269985\n
    vn -0.000000 1.000000 -0.000000\n
    vn -0.569800 0.776168 -0.269985\n
    vn -0.432849 0.776168 0.458482\n
    vn -0.000000 1.000000 -0.000000\n
    vn -0.432849 0.776168 0.458482\n
    vn 0.302285 0.776168 0.553342\n
    vn -0.000000 1.000000 -0.000000\n
    vn 0.302285 0.776168 0.553342\n
    vn 0.619671 0.776168 -0.116498\n
    vn -0.000000 1.000000 -0.000000\n
    vn 0.619671 0.776168 -0.116498\n
    vn 0.080693 0.776168 -0.625342\n
    vn -0.000000 1.000000 -0.000000\n
    f 1/1/1 2/2/2 6/7/3\n
    f 6/7/3 2/2/2 7/8/4\n
    f 2/2/5 3/3/6 7/8/7\n
    f 7/8/7 3/3/6 8/9/8\n
    f 3/3/9 4/4/10 8/9/11\n
    f 8/9/11 4/4/10 9/10/12\n
    f 4/4/13 5/5/14 9/10/15\n
    f 9/10/15 5/5/14 10/11/16\n
    f 5/5/17 1/6/18 10/11/19\n
    f 10/11/19 1/6/18 6/12/20\n
    f 6/7/21 7/8/22 11/13/23\n
    f 11/13/23 7/8/22 12/14/24\n
    f 7/8/25 8/9/26 12/14/27\n
    f 12/14/27 8/9/26 13/15/28\n
    f 8/9/29 9/10/30 13/15/31\n
    f 13/15/31 9/10/30 14/16/32\n
    f 9/10/33 10/11/34 14/16/35\n
    f 14/16/35 10/11/34 15/17/36\n
    f 10/11/37 6/12/38 15/17/39\n
    f 15/17/39 6/12/38 11/18/40\n
    f 11/13/41 12/14/42 16/19/43\n
    f 16/19/43 12/14/42 17/20/44\n
    f 12/14/45 13/15/46 17/20/47\n
    f 17/20/47 13/15/46 18/21/48\n
    f 13/15/49 14/16/50 18/21/51\n
    f 18/21/51 14/16/50 19/22/52\n
    f 14/16/53 15/17/54 19/22/55\n
    f 19/22/55 15/17/54 20/23/56\n
    f 15/17/57 11/18/58 20/23/59\n
    f 20/23/59 11/18/58 16/24/60\n
    f 2/2/61 1/1/62 21/25/63\n
    f 3/3/64 2/2/65 21/26/66\n
    f 4/4/67 3/3/68 21/27/69\n
    f 5/5/70 4/4/71 21/28/72\n
    f 1/6/73 5/5/74 21/29/75\n
    f 16/19/76 17/20/77 22/30/78\n
    f 17/20/79 18/21/80 22/31/81\n
    f 18/21/82 19/22/83 22/32/84\n
    f 19/22/85 20/23/86 22/33/87\n
    f 20/23/88 16/24/89 22/34/90\n
);

const Vector2D* getSamplePoints2() {
    return kSamplePoints2;
}

size_t getNumberOfSamplePoints2() {
    return sizeof(kSamplePoints2) / sizeof(kSamplePoints2[0]);
}

const Vector3D* getSamplePoints3() {
    return kSamplePoints3;
}

size_t getNumberOfSamplePoints3() {
    return sizeof(kSamplePoints3) / sizeof(kSamplePoints3[0]);
}

const Vector2D* getSampleDirs2() {
    return kSampleDirs2;
}

size_t getNumberOfSampleDirs2() {
    return sizeof(kSampleDirs2) / sizeof(kSampleDirs2[0]);
}

const Vector3D* getSampleDirs3() {
    return kSampleDirs3;
}

size_t getNumberOfSampleDirs3() {
    return sizeof(kSampleDirs3) / sizeof(kSampleDirs3[0]);
}

const char* getCubeTriMesh3x3x3Obj() {
    return kCubeTriMesh3x3x3AsObj;
}

const char* getSphereTriMesh5x5Obj() {
    return kSphereTriMesh5x5Obj;
}

}  // namespace vox
