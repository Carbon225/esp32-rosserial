idf_component_register(
    SRCS "ESP32Hardware.cpp" "ros_lib/time.cpp" "ros_lib/duration.cpp" "Kconfig"
    INCLUDE_DIRS "ros_lib"
    PRIV_INCLUDE_DIRS "PrivateInclude")
