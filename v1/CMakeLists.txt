cmake_minimum_required(VERSION 3.12)
project(bowling_kata)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(tests/lib/googletest/googlemock/include)
include_directories(tests/lib/googletest/googlemock/include/gmock)
include_directories(tests/lib/googletest/googlemock/include/gmock/internal)
include_directories(tests/lib/googletest/googlemock/include/gmock/internal/custom)
include_directories(tests/lib/googletest/googlemock/test)
include_directories(tests/lib/googletest/googletest/include)
include_directories(tests/lib/googletest/googletest/include/gtest)
include_directories(tests/lib/googletest/googletest/include/gtest/internal)
include_directories(tests/lib/googletest/googletest/include/gtest/internal/custom)
include_directories(tests/lib/googletest/googletest/samples)
include_directories(tests/lib/googletest/googletest/src)
include_directories(tests/lib/googletest/googletest/test)
include_directories(tests/lib/googletest/googletest/xcode/Samples/FrameworkSample)

add_executable(bowling_kata
        src/Bowling.h
        src/Frame.h
        tests/lib/googletest/googlemock/include/gmock/internal/custom/gmock-generated-actions.h
        tests/lib/googletest/googlemock/include/gmock/internal/custom/gmock-matchers.h
        tests/lib/googletest/googlemock/include/gmock/internal/custom/gmock-port.h
        tests/lib/googletest/googlemock/include/gmock/internal/gmock-generated-internal-utils.h
        tests/lib/googletest/googlemock/include/gmock/internal/gmock-internal-utils.h
        tests/lib/googletest/googlemock/include/gmock/internal/gmock-port.h
        tests/lib/googletest/googlemock/include/gmock/gmock-actions.h
        tests/lib/googletest/googlemock/include/gmock/gmock-cardinalities.h
        tests/lib/googletest/googlemock/include/gmock/gmock-generated-actions.h
        tests/lib/googletest/googlemock/include/gmock/gmock-generated-function-mockers.h
        tests/lib/googletest/googlemock/include/gmock/gmock-generated-matchers.h
        tests/lib/googletest/googlemock/include/gmock/gmock-generated-nice-strict.h
        tests/lib/googletest/googlemock/include/gmock/gmock-matchers.h
        tests/lib/googletest/googlemock/include/gmock/gmock-more-actions.h
        tests/lib/googletest/googlemock/include/gmock/gmock-more-matchers.h
        tests/lib/googletest/googlemock/include/gmock/gmock-spec-builders.h
        tests/lib/googletest/googlemock/include/gmock/gmock.h
        tests/lib/googletest/googlemock/src/gmock-all.cc
        tests/lib/googletest/googlemock/src/gmock-cardinalities.cc
        tests/lib/googletest/googlemock/src/gmock-internal-utils.cc
        tests/lib/googletest/googlemock/src/gmock-matchers.cc
        tests/lib/googletest/googlemock/src/gmock-spec-builders.cc
        tests/lib/googletest/googlemock/src/gmock.cc
        tests/lib/googletest/googlemock/src/gmock_main.cc
        tests/lib/googletest/googlemock/test/gmock-actions_test.cc
        tests/lib/googletest/googlemock/test/gmock-cardinalities_test.cc
        tests/lib/googletest/googlemock/test/gmock-generated-actions_test.cc
        tests/lib/googletest/googlemock/test/gmock-generated-function-mockers_test.cc
        tests/lib/googletest/googlemock/test/gmock-generated-internal-utils_test.cc
        tests/lib/googletest/googlemock/test/gmock-generated-matchers_test.cc
        tests/lib/googletest/googlemock/test/gmock-internal-utils_test.cc
        tests/lib/googletest/googlemock/test/gmock-matchers_test.cc
        tests/lib/googletest/googlemock/test/gmock-more-actions_test.cc
        tests/lib/googletest/googlemock/test/gmock-nice-strict_test.cc
        tests/lib/googletest/googlemock/test/gmock-port_test.cc
        tests/lib/googletest/googlemock/test/gmock-spec-builders_test.cc
        tests/lib/googletest/googlemock/test/gmock_all_test.cc
        tests/lib/googletest/googlemock/test/gmock_ex_test.cc
        tests/lib/googletest/googlemock/test/gmock_leak_test_.cc
        tests/lib/googletest/googlemock/test/gmock_link2_test.cc
        tests/lib/googletest/googlemock/test/gmock_link_test.cc
        tests/lib/googletest/googlemock/test/gmock_link_test.h
        tests/lib/googletest/googlemock/test/gmock_output_test_.cc
        tests/lib/googletest/googlemock/test/gmock_stress_test.cc
        tests/lib/googletest/googlemock/test/gmock_test.cc
        tests/lib/googletest/googletest/codegear/gtest_all.cc
        tests/lib/googletest/googletest/codegear/gtest_link.cc
        tests/lib/googletest/googletest/include/gtest/internal/custom/gtest-port.h
        tests/lib/googletest/googletest/include/gtest/internal/custom/gtest-printers.h
        tests/lib/googletest/googletest/include/gtest/internal/custom/gtest.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-death-test-internal.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-filepath.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-internal.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-linked_ptr.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-param-util-generated.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-param-util.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-port-arch.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-port.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-string.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-tuple.h
        tests/lib/googletest/googletest/include/gtest/internal/gtest-type-util.h
        tests/lib/googletest/googletest/include/gtest/gtest-death-test.h
        tests/lib/googletest/googletest/include/gtest/gtest-message.h
        tests/lib/googletest/googletest/include/gtest/gtest-param-test.h
        tests/lib/googletest/googletest/include/gtest/gtest-printers.h
        tests/lib/googletest/googletest/include/gtest/gtest-spi.h
        tests/lib/googletest/googletest/include/gtest/gtest-test-part.h
        tests/lib/googletest/googletest/include/gtest/gtest-typed-test.h
        tests/lib/googletest/googletest/include/gtest/gtest.h
        tests/lib/googletest/googletest/include/gtest/gtest_pred_impl.h
        tests/lib/googletest/googletest/include/gtest/gtest_prod.h
        tests/lib/googletest/googletest/samples/prime_tables.h
        tests/lib/googletest/googletest/samples/sample1.cc
        tests/lib/googletest/googletest/samples/sample1.h
        tests/lib/googletest/googletest/samples/sample10_unittest.cc
        tests/lib/googletest/googletest/samples/sample1_unittest.cc
        tests/lib/googletest/googletest/samples/sample2.cc
        tests/lib/googletest/googletest/samples/sample2.h
        tests/lib/googletest/googletest/samples/sample2_unittest.cc
        tests/lib/googletest/googletest/samples/sample3-inl.h
        tests/lib/googletest/googletest/samples/sample3_unittest.cc
        tests/lib/googletest/googletest/samples/sample4.cc
        tests/lib/googletest/googletest/samples/sample4.h
        tests/lib/googletest/googletest/samples/sample4_unittest.cc
        tests/lib/googletest/googletest/samples/sample5_unittest.cc
        tests/lib/googletest/googletest/samples/sample6_unittest.cc
        tests/lib/googletest/googletest/samples/sample7_unittest.cc
        tests/lib/googletest/googletest/samples/sample8_unittest.cc
        tests/lib/googletest/googletest/samples/sample9_unittest.cc
        tests/lib/googletest/googletest/src/gtest-all.cc
        tests/lib/googletest/googletest/src/gtest-death-test.cc
        tests/lib/googletest/googletest/src/gtest-filepath.cc
        tests/lib/googletest/googletest/src/gtest-internal-inl.h
        tests/lib/googletest/googletest/src/gtest-port.cc
        tests/lib/googletest/googletest/src/gtest-printers.cc
        tests/lib/googletest/googletest/src/gtest-test-part.cc
        tests/lib/googletest/googletest/src/gtest-typed-test.cc
        tests/lib/googletest/googletest/src/gtest.cc
        tests/lib/googletest/googletest/src/gtest_main.cc
        tests/lib/googletest/googletest/test/gtest-death-test_ex_test.cc
        tests/lib/googletest/googletest/test/gtest-death-test_test.cc
        tests/lib/googletest/googletest/test/gtest-filepath_test.cc
        tests/lib/googletest/googletest/test/gtest-linked_ptr_test.cc
        tests/lib/googletest/googletest/test/gtest-listener_test.cc
        tests/lib/googletest/googletest/test/gtest-message_test.cc
        tests/lib/googletest/googletest/test/gtest-options_test.cc
        tests/lib/googletest/googletest/test/gtest-param-test2_test.cc
        tests/lib/googletest/googletest/test/gtest-param-test_test.cc
        tests/lib/googletest/googletest/test/gtest-param-test_test.h
        tests/lib/googletest/googletest/test/gtest-port_test.cc
        tests/lib/googletest/googletest/test/gtest-printers_test.cc
        tests/lib/googletest/googletest/test/gtest-test-part_test.cc
        tests/lib/googletest/googletest/test/gtest-tuple_test.cc
        tests/lib/googletest/googletest/test/gtest-typed-test2_test.cc
        tests/lib/googletest/googletest/test/gtest-typed-test_test.cc
        tests/lib/googletest/googletest/test/gtest-typed-test_test.h
        tests/lib/googletest/googletest/test/gtest-unittest-api_test.cc
        tests/lib/googletest/googletest/test/gtest_all_test.cc
        tests/lib/googletest/googletest/test/gtest_assert_by_exception_test.cc
        tests/lib/googletest/googletest/test/gtest_break_on_failure_unittest_.cc
        tests/lib/googletest/googletest/test/gtest_catch_exceptions_test_.cc
        tests/lib/googletest/googletest/test/gtest_color_test_.cc
        tests/lib/googletest/googletest/test/gtest_env_var_test_.cc
        tests/lib/googletest/googletest/test/gtest_environment_test.cc
        tests/lib/googletest/googletest/test/gtest_filter_unittest_.cc
        tests/lib/googletest/googletest/test/gtest_help_test_.cc
        tests/lib/googletest/googletest/test/gtest_list_tests_unittest_.cc
        tests/lib/googletest/googletest/test/gtest_main_unittest.cc
        tests/lib/googletest/googletest/test/gtest_no_test_unittest.cc
        tests/lib/googletest/googletest/test/gtest_output_test_.cc
        tests/lib/googletest/googletest/test/gtest_pred_impl_unittest.cc
        tests/lib/googletest/googletest/test/gtest_premature_exit_test.cc
        tests/lib/googletest/googletest/test/gtest_prod_test.cc
        tests/lib/googletest/googletest/test/gtest_repeat_test.cc
        tests/lib/googletest/googletest/test/gtest_shuffle_test_.cc
        tests/lib/googletest/googletest/test/gtest_sole_header_test.cc
        tests/lib/googletest/googletest/test/gtest_stress_test.cc
        tests/lib/googletest/googletest/test/gtest_testbridge_test_.cc
        tests/lib/googletest/googletest/test/gtest_throw_on_failure_ex_test.cc
        tests/lib/googletest/googletest/test/gtest_throw_on_failure_test_.cc
        tests/lib/googletest/googletest/test/gtest_uninitialized_test_.cc
        tests/lib/googletest/googletest/test/gtest_unittest.cc
        tests/lib/googletest/googletest/test/gtest_xml_outfile1_test_.cc
        tests/lib/googletest/googletest/test/gtest_xml_outfile2_test_.cc
        tests/lib/googletest/googletest/test/gtest_xml_output_unittest_.cc
        tests/lib/googletest/googletest/test/production.cc
        tests/lib/googletest/googletest/test/production.h
        tests/lib/googletest/googletest/xcode/Samples/FrameworkSample/widget.cc
        tests/lib/googletest/googletest/xcode/Samples/FrameworkSample/widget.h
        tests/lib/googletest/googletest/xcode/Samples/FrameworkSample/widget_test.cc
        tests/unit_tests/Bowling.cpp
        tests/unit_tests/Frame.cpp
        main.cpp)
