SUBDIRS = src tests

if UNIT_TESTS_ENABLED
clean_coverage:
	rm -fr coverage*
	find . -name "*.gcda" -delete
coverage_init: clean_coverage check
	lcov  --gcov-tool gcov-11 --initial --capture  --directory . --include "*src*"  --output-file coverage-base.info
coverage: coverage_init check
	lcov  --gcov-tool gcov-11 --capture  --directory . --include "*src*"  --output-file coverage.info
	lcov --list coverage.info # debug info
coverage_diff: coverage
	lcov  --gcov-tool gcov-11 --add-tracefile coverage-base.info --add-tracefile coverage.info --output-file coverage-total.info --rc genhtml_demangle_cpp=1
	genhtml coverage-total.info --output-directory coverage-results --demangle-cpp
endif
