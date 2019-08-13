# Enum Option

## Overview / Purpose

Enumeration Option

|Enumerator|Value|Description|
|----------|-----|-----------|
|OPTION\_UNSPECIFIED|0|Unspecifed Option|
|OPTION\_BACKLIGHT\_COMPENSATION|1|Enable / disable color backlight compensation \(unsupported\)|
|OPTION\_BRIGHTNESS|2|Color image brightness \(supported on color sensor only: -4.0 to 4.0, step 1.0\)|
|OPTION\_CONTRAST|3|Color image contrast \(supported on color sensor only: -4.0 to 4.0, step 1.0\)|
|OPTION\_EXPOSURE|4|Controls exposure time of color camera. Setting any value will disable auto exposure \(supported on depth sensor only: 20.0 to 166000.0, step 20.0\)|
|OPTION\_GAIN|5|Color image gain \(supported on depth sensor only: 16.0 to 248.0, step 1.0\)|
|OPTION\_GAMMA|6|Color image gamma setting \(unsupported\)|
|OPTION\_HUE|7|Color image hue \(unsupported\)|
|OPTION\_SATURATION|8|Color image saturation setting \(supported on color sensor only: -4.0 to 4.0, step 1.0\)|
|OPTION\_SHARPNESS|9|Color image sharpness setting \(unsupported\)|
|OPTION\_WHITE\_BALANCE|10|Controls white balance of color image. Setting any value will disable auto white balance \(unsupported\)|
|OPTION\_ENABLE\_AUTO\_EXPOSURE|11|Enable / disable color image auto-exposure \(supported on depth sensor only: 0.0 to 1.0, step 1.0\)|
|OPTION\_ENABLE\_AUTO\_WHITE\_BALANCE|12|Enable / disable color image auto-white-balance \(unsupported\)|
|OPTION\_VISUAL\_PRESET|13|Provide access to several recommend sets of option presets for the depth camera \(supported on depth sensor only: 0.0 to 5.0, step 1.0\)|
|OPTION\_LASER\_POWER|14|Power of the projector, with 0 meaning projector off \(unsupported\)|
|OPTION\_ACCURACY|15|Sets the number of patterns projected per frame. The higher the accuracy value the more patterns projected \(unsupported\)|
|OPTION\_MOTION\_RANGE|16|Motion vs. Range trade-off, with lower values allowing for better motion sensitivity and higher values allowing for better depth range \(unsupported\)|
|OPTION\_FILTER\_OPTION|17|Sets the filter to apply to each depth frame. Each one of the filter is optimized per the application requirements \(unsupported\)|
|OPTION\_CONFIDENCE\_THRESHOLD|18|The confidence level threshold used by the Depth algorithm pipe to set whether a pixel will get a valid range or will be marked with invalid range \(unsupported\)|
|OPTION\_EMITTER\_ENABLED|19|Laser Emitter enabled \(unsupported\)|
|OPTION\_FRAMES\_QUEUE\_SIZE|20|Number of frames the user is allowed to keep per stream. Trying to hold-on to more frames will cause frame-drops \(supported on depth sensor only: 0.0 to 32.0, step 1.0\)|
|OPTION\_TOTAL\_FRAME\_DROPS|21|Total number of detected frame drops from all streams \(unsupported\)|
|OPTION\_AUTO\_EXPOSURE\_MODE|22|Auto-Exposure modes: Static, Anti-Flicker and Hybrid \(unsupported\)|
|OPTION\_POWER\_LINE\_FREQUENCY|23|Power Line Frequency control for anti-flickering Off/50Hz/60Hz/Auto \(unsupported\)|
|OPTION\_ASIC\_TEMPERATURE|24|Current Asic Temperature \(supported on depth sensor only: Read Only -40.0 to 125.0\)|
|OPTION\_ERROR\_POLLING\_ENABLED|25|Disable error handling \(supported on depth sensor only: 0.0 to 1.0, step 1.0\)|
|OPTION\_PROJECTOR\_TEMPERATURE|26|Current Projector Temperature \(unsupported\)|
|OPTION\_OUTPUT\_TRIGGER\_ENABLED|27|Enable / disable trigger to be outputed from the camera to any external device on every depth frame \(supported on depth sensor only: 0.0 to 1.0, step 1.0\)|
|OPTION\_MOTION\_MODULE\_TEMPERATURE|28|Current Motion-Module Temperature \(unsupported\)|
|OPTION\_DEPTH\_UNITS|29|Number of meters represented by a single depth unit \(supported on depth sensor only: 0.0001 to 0.0100, step 0.000001\)|
|OPTION\_ENABLE\_MOTION\_CORRECTION|30|Enable/Disable automatic correction of the motion data \(unsupported\)|
|OPTION\_AUTO\_EXPOSURE\_PRIORITY|31|Allows sensor to dynamically ajust the frame rate depending on lighting conditions \(unsupported\)|
|OPTION\_COLOR\_SCHEME|32|Color scheme for data visualization \(unsupported\)|
|OPTION\_HISTOGRAM\_EQUALIZATION\_ENABLED|33|Perform histogram equalization post-processing on the depth data \(unsupported\)|
|OPTION\_MIN\_DISTANCE|34|Minimal distance to the target \(unsupported\)|
|OPTION\_MAX\_DISTANCE|35|Maximum distance to the target \(unsupported\)|
|OPTION\_TEXTURE\_SOURCE|36|Texture mapping stream unique ID \(unsupported\)|
|OPTION\_FILTER\_MAGNITUDE|37|The 2D-filter effect. The specific interpretation is given within the context of the filter \(unsupported\)|
|OPTION\_FILTER\_SMOOTH\_ALPHA|38|2D-filter parameter controls the weight/radius for smoothing \(unsupported\)|
|OPTION\_FILTER\_SMOOTH\_DELTA|39|2D-filter range/validity threshold \(unsupported\)|
|OPTION\_HOLES\_FILL|40|Enhance depth data post-processing with holes filling where appropriate \(unsupported\)|
|OPTION\_STEREO\_BASELINE|41|The distance in mm between the first and the second imagers in stereo-based depth cameras \(supported on depth sensor only: 55.241055 to 55.241055, step 0.0\)|
|OPTION\_AUTO\_EXPOSURE\_CONVERGE\_STEP|42|Allows dynamically ajust the converge step value of the target exposure in Auto-Exposure algorithm \(unsupported\)|

**Parent topic:** [VisionConfig \(Python\)](../../summary_pages/VisionConfig.md)

