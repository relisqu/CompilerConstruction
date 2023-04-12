test:
	@mkdir -p cmake-build-debug
	cmake --build cmake-build-debug --target CompilerConstruction_run -- -j 4
	@cd cmake-build-debug && cmake ..
	@cd cmake-build-debug && ctest -V