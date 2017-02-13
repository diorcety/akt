cmake_minimum_required(VERSION 2.8)

## section: Macro
MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
    IF (MSVC)
        GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
        SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${PrecompiledBasename}.pch")
        SET(Sources ${${SourcesVar}})

        SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
                PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
                OBJECT_OUTPUTS "${PrecompiledBinary}")
        SET_SOURCE_FILES_PROPERTIES(${Sources}
                PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledBinary}\" /FI\"${PrecompiledBinary}\" /Fp\"${PrecompiledBinary}\""
                OBJECT_DEPENDS "${PrecompiledBinary}")
        # Add precompiled header to SourcesVar
        LIST(APPEND ${SourcesVar} ${PrecompiledSource})
    ENDIF (MSVC)
ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

## start setting
SET(this_target Armadillo_KeyTool)
PROJECT(${this_target})

## section: source files
SET(${this_target}_SOURCE_FILES
        functions/about.cpp
        functions/analysis.cpp
        functions/CertTool_brute.cpp
        functions/CertTool_debugger.cpp
        functions/CertTool_decrypt.cpp
        functions/CertTool_dialog.cpp
        functions/CertTool_global.cpp
        functions/CertTool_parser.cpp
        functions/encdec.cpp
        functions/EVLog_debugger.cpp
        functions/EVLog_global.cpp
        functions/EVLog_maindlg.cpp
        functions/help_dialog.cpp
        functions/InlineHelper_codegen.cpp
        functions/InlineHelper_debugger.cpp
        functions/InlineHelper_decrypt.cpp
        functions/InlineHelper_dialog.cpp
        functions/InlineHelper_global.cpp
        functions/InlineHelper_plugins.cpp
        functions/keygenerate.cpp
        functions/keygen/keygen_bigint.cpp
        functions/keygen/keygen_blowfish.cpp
        functions/keygen/keygen_crc32.cpp
        functions/keygen/keygen_ecc.cpp
        functions/keygen/keygen_info.cpp
        functions/keygen/keygen_main.cpp
        functions/keygen/keygen_md5.cpp
        functions/keygen/keygen_misc.cpp
        functions/keygen/keygen_random.cpp
        functions/LicenceRemoval_debugger.cpp
        functions/Misc_checksum.cpp
        functions/Misc_currentsym.cpp
        functions/Misc_dialog.cpp
        functions/Misc_global.cpp
        functions/Misc_projectid.cpp
        functions/Misc_sectiondeleter.cpp
        functions/Misc_verifysym.cpp
        functions/VersionFind_decode.cpp
        functions/VersionFind_dialog.cpp
        functions/VersionFind_extraoptions.cpp
        functions/VersionFind_global.cpp
        functions/VersionFind_rawoptions.cpp
        functions/VersionFind_version.cpp
        functions/_global.cpp
        main.cpp
        tabs.cpp
        resource.rc
        )

## section: header files
SET(${this_target}_HEADER_FILES
        BeaEngine/basic_types.h
        BeaEngine/BeaEngine.h
        BeaEngine/export.h
        BeaEngine/macros.h
        functions/about.h
        functions/analysis.h
        functions/CertTool_brute.h
        functions/CertTool_debugger.h
        functions/CertTool_decrypt.h
        functions/CertTool_dialog.h
        functions/CertTool_global.h
        functions/CertTool_parser.h
        functions/encdec.h
        functions/EVLog_debugger.h
        functions/EVLog_global.h
        functions/EVLog_maindlg.h
        functions/help_dialog.h
        functions/InlineHelper_codegen.h
        functions/InlineHelper_debugger.h
        functions/InlineHelper_decrypt.h
        functions/InlineHelper_dialog.h
        functions/InlineHelper_global.h
        functions/InlineHelper_plugins.h
        functions/keygenerate.h
        functions/keygen/keygen_bigint.h
        functions/keygen/keygen_blowfish.h
        functions/keygen/keygen_crc32.h
        functions/keygen/keygen_ecc.h
        functions/keygen/keygen_info.h
        functions/keygen/keygen_main.h
        functions/keygen/keygen_md5.h
        functions/keygen/keygen_misc.h
        functions/keygen/keygen_random.h
        functions/LicenceRemoval_debugger.h
        functions/Misc_checksum.h
        functions/Misc_currentsym.h
        functions/Misc_dialog.h
        functions/Misc_global.h
        functions/Misc_projectid.h
        functions/Misc_sectiondeleter.h
        functions/Misc_verifysym.h
        functions/VersionFind_decode.h
        functions/VersionFind_dialog.h
        functions/VersionFind_extraoptions.h
        functions/VersionFind_global.h
        functions/VersionFind_rawoptions.h
        functions/VersionFind_version.h
        functions/_global.h
        main.h
        resource.h
        tabs.h
        template.h
        TitanEngine/TitanEngine.h
        )

SOURCE_GROUP("Header Files//BeaEngine" FILES
        BeaEngine/basic_types.h
        BeaEngine/BeaEngine.h
        BeaEngine/export.h
        BeaEngine/macros.h
        )

SOURCE_GROUP("Header Files//TitanEngine" FILES
        TitanEngine/TitanEngine.h
        )

SOURCE_GROUP("Header Files//functions" FILES
        functions/_global.h
        functions/about.h
        functions/analysis.h
        functions/CertTool_brute.h
        functions/CertTool_debugger.h
        functions/CertTool_decrypt.h
        functions/CertTool_dialog.h
        functions/CertTool_global.h
        functions/CertTool_parser.h
        functions/encdec.h
        functions/EVLog_debugger.h
        functions/EVLog_global.h
        functions/EVLog_maindlg.h
        functions/help_dialog.h
        functions/InlineHelper_codegen.h
        functions/InlineHelper_debugger.h
        functions/InlineHelper_decrypt.h
        functions/InlineHelper_dialog.h
        functions/InlineHelper_global.h
        functions/InlineHelper_plugins.h
        functions/keygenerate.h
        functions/LicenceRemoval_debugger.h
        functions/Misc_checksum.h
        functions/Misc_currentsym.h
        functions/Misc_dialog.h
        functions/Misc_global.h
        functions/Misc_projectid.h
        functions/Misc_sectiondeleter.h
        functions/Misc_verifysym.h
        functions/VersionFind_decode.h
        functions/VersionFind_dialog.h
        functions/VersionFind_extraoptions.h
        functions/VersionFind_global.h
        functions/VersionFind_rawoptions.h
        functions/VersionFind_version.h
        )

SOURCE_GROUP("Source Files//functions//keygen" FILES
        functions/keygen/keygen_bigint.cpp
        functions/keygen/keygen_blowfish.cpp
        functions/keygen/keygen_crc32.cpp
        functions/keygen/keygen_ecc.cpp
        functions/keygen/keygen_info.cpp
        functions/keygen/keygen_main.cpp
        functions/keygen/keygen_md5.cpp
        functions/keygen/keygen_misc.cpp
        functions/keygen/keygen_random.cpp
        )

SOURCE_GROUP("Header Files" FILES
        main.h
        resource.h
        tabs.h
        template.h
        )

SOURCE_GROUP("Source Files" FILES
        main.cpp
        tabs.cpp
        )

SOURCE_GROUP("Resource Files" FILES
        resource.rc
        )

SOURCE_GROUP("Source Files//functions" FILES
        functions/_global.cpp
        functions/about.cpp
        functions/analysis.cpp
        functions/CertTool_brute.cpp
        functions/CertTool_debugger.cpp
        functions/CertTool_decrypt.cpp
        functions/CertTool_dialog.cpp
        functions/CertTool_global.cpp
        functions/CertTool_parser.cpp
        functions/encdec.cpp
        functions/EVLog_debugger.cpp
        functions/EVLog_global.cpp
        functions/EVLog_maindlg.cpp
        functions/help_dialog.cpp
        functions/InlineHelper_codegen.cpp
        functions/InlineHelper_debugger.cpp
        functions/InlineHelper_decrypt.cpp
        functions/InlineHelper_dialog.cpp
        functions/InlineHelper_global.cpp
        functions/InlineHelper_plugins.cpp
        functions/keygenerate.cpp
        functions/LicenceRemoval_debugger.cpp
        functions/Misc_checksum.cpp
        functions/Misc_currentsym.cpp
        functions/Misc_dialog.cpp
        functions/Misc_global.cpp
        functions/Misc_projectid.cpp
        functions/Misc_sectiondeleter.cpp
        functions/Misc_verifysym.cpp
        functions/VersionFind_decode.cpp
        functions/VersionFind_dialog.cpp
        functions/VersionFind_extraoptions.cpp
        functions/VersionFind_global.cpp
        functions/VersionFind_rawoptions.cpp
        functions/VersionFind_version.cpp
        )

SOURCE_GROUP("Header Files//functions//keygen" FILES
        functions/keygen/keygen_bigint.h
        functions/keygen/keygen_blowfish.h
        functions/keygen/keygen_crc32.h
        functions/keygen/keygen_ecc.h
        functions/keygen/keygen_info.h
        functions/keygen/keygen_main.h
        functions/keygen/keygen_md5.h
        functions/keygen/keygen_misc.h
        functions/keygen/keygen_random.h
        )

## section: precompiled header	
#ADD_MSVC_PRECOMPILED_HEADER("precompiled.h" "precompiled.cpp" MySources)
#ADD_LIBRARY(MyLibrary ${MySources})

SET_SOURCE_FILES_PROPERTIES(${this_target}_HEADER_FILES PROPERTIES HEADER_FILE_ONLY TRUE)
LIST(APPEND ${this_target}_SOURCE_FILES ${${this_target}_HEADER_FILES})

## section: add definitions
ADD_DEFINITIONS(-DX64_DBG_EXPORTS)

## section: add target
ADD_EXECUTABLE(${this_target} WIN32 ${${this_target}_SOURCE_FILES})
set_property(TARGET ${this_target} PROPERTY WIN32_EXECUTABLE true)

## section: set link libraries
TARGET_LINK_LIBRARIES(${this_target}
        ${CMAKE_SOURCE_DIR}/TitanEngine/TitanEngine_x86.lib
        ${CMAKE_SOURCE_DIR}/BeaEngine/BeaEngine.lib
        uxtheme.lib
        comctl32.lib
        kernel32.lib
        user32.lib
        gdi32.lib
        winspool.lib
        comdlg32.lib
        advapi32.lib
        shell32.lib
        ole32.lib
        oleaut32.lib
        uuid.lib
        odbc32.lib
        odbccp32.lib
        )