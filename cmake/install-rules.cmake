install(
    TARGETS RNA-tool_exe
    RUNTIME COMPONENT RNA-tool_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
