function(ProtectTarget)
  set(optional FATAL)
  set(singleArgument TARGET)

  cmake_parse_arguments(ProtectTarget "${optional}" "${singleArgument}" "" ${ARGV})

  if(NOT ProtectTarget_TARGET)
    message(FATAL_ERROR "Must specify a target name to protect")
    return()
  endif()

  if(ProtectedTargets_${ProtectTarget_TARGET})
    if(ProtectTarget_FATAL)
      message(FATAL_ERROR "Target ${ProtectTarget_TARGET} already defined")
    else()
      message(WARNING "Target ${ProtectTarget_TARGET} already defined")
      set(ProtectTarget_FOUND TRUE PARENT_SCOPE)
    endif()
    return()
  endif()

  set(ProtectedTargets_${ProtectTarget_TARGET} TRUE CACHE INTERNAL "${ProtectTarget_TARGET} is protected against double inclusion")

endfunction()
  
