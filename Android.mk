# Android.mk for love-android

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := love-imgui
LOCAL_MODULE_FILENAME := imgui

LOCAL_ARM_NEON := true

LOCAL_SRC_FILES := \
	src/libimgui/imgui.cpp \
	src/libimgui/imgui_draw.cpp \
	src/libimgui/imgui_widgets.cpp \
	src/imgui_impl.cpp \
	src/wrap_imgui_impl.cpp \
	src/dostring_cache.cpp

LOCAL_SHARED_LIBRARIES := liblove

include $(BUILD_SHARED_LIBRARY)
