SUBDIRS = src tests

if UNIT_TESTS_ENABLED
clean_coverage:
	rm -fr coverage*
	find . -name "*.gcda" -delete
coverage_init: clean_coverage check
	lcov  --gcov-tool gcov-11 --initial --capture  --directory . \
        --exclude "*src/adapters/*" \
        --exclude "*src/main.cpp" \
        --exclude "*src/utils.cpp" \
        --include "*src*" \
        --output-file coverage-base.info
coverage_dirty: check
	lcov  --gcov-tool gcov-11 --capture  --directory . \
        --exclude "*src/adapters/*" \
        --exclude "*src/main.cpp" \
        --exclude "*src/utils.cpp" \
        --exclude "*tests/*" \
        --include "*src*" \
        --output-file coverage.info
	lcov --list coverage.info # debug info
	genhtml coverage.info --output-directory coverage-results --demangle-cpp
coverage: coverage_init coverage_dirty
coverage_diff: coverage
	lcov  --gcov-tool gcov-11 --add-tracefile coverage-base.info --add-tracefile coverage.info --output-file coverage-total.info --rc genhtml_demangle_cpp=1
	genhtml coverage-total.info --output-directory coverage-results --demangle-cpp
endif
