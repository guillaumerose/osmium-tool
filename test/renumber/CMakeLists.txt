#-----------------------------------------------------------------------------
#
#  CMake Config
#
#  Osmium Tool Tests - renumber
#
#-----------------------------------------------------------------------------

function(check_renumber _name _input _output)
    check_output(renumber ${_name} "renumber --generator=test -f osm renumber/${_input}" "renumber/${_output}")
endfunction()

function(check_renumber_nodes _name _input _output)
    check_output(renumber ${_name} "renumber --generator=test -t node -f osm renumber/${_input}" "renumber/${_output}")
endfunction()

function(check_renumber2 _name _in1 _in2 _out)
    set(_idxdir "${PROJECT_BINARY_DIR}/test/renumber/index")
    if(WIN32)
        set(_devnull "nul")
    else()
        set(_devnull "/dev/null")
    endif()
    check_output2(renumber ${_name} ${_idxdir}
                  "renumber --index-directory=${_idxdir} --generator=test -f osm --overwrite -o ${_devnull} renumber/${_in1}"
                  "renumber --index-directory=${_idxdir} --generator=test -f osc renumber/${_in2}"
                  "renumber/${_out}"
    )
endfunction()

check_renumber(sorted input-sorted.osm output-sorted.osm)
check_renumber_nodes(nodes-sorted input-sorted.osm output-sorted-n.osm)

check_renumber2(change input-sorted.osm input-change.osc output-change.osc)

#-----------------------------------------------------------------------------

# input data not ordered properly

add_test(NAME renumber-fail-order-n COMMAND osmium renumber ${CMAKE_SOURCE_DIR}/test/order/fail-order-n.osm -f osm)
set_tests_properties(renumber-fail-order-n PROPERTIES WILL_FAIL true)

add_test(NAME renumber-fail-order-w COMMAND osmium renumber ${CMAKE_SOURCE_DIR}/test/order/fail-order-w.osm -f osm)
set_tests_properties(renumber-fail-order-w PROPERTIES WILL_FAIL true)

add_test(NAME renumber-fail-order-r COMMAND osmium renumber ${CMAKE_SOURCE_DIR}/test/order/fail-order-r.osm -f osm)
set_tests_properties(renumber-fail-order-r PROPERTIES WILL_FAIL true)

add_test(NAME renumber-fail-order-wn COMMAND osmium renumber ${CMAKE_SOURCE_DIR}/test/order/fail-order-wn.osm -f osm)
set_tests_properties(renumber-fail-order-wn PROPERTIES WILL_FAIL true)

add_test(NAME renumber-fail-order-rw COMMAND osmium renumber ${CMAKE_SOURCE_DIR}/test/order/fail-order-rw.osm -f osm)
set_tests_properties(renumber-fail-order-rw PROPERTIES WILL_FAIL true)


#-----------------------------------------------------------------------------
