# This file is generated by gyp; do not edit.


LOCAL_PATH := $(call my-dir)
GYP_CONFIGURATION ?= Debug
GYP_VAR_PREFIX ?=
GYP_HOST_VAR_PREFIX ?=
GYP_HOST_MULTILIB ?= first

include $(LOCAL_PATH)/libledger-core-android.target.mk
include $(LOCAL_PATH)/support-lib/djinni_jni.target.mk

# "gyp_all_modules" is a concatenation of the "gyp_all_modules" targets from
# all the included sub-makefiles. This is just here to clarify.
gyp_all_modules: