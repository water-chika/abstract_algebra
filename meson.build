project('abstract_algebra', ['cpp'],
  default_options: ['cpp_std=c++23'])

abstract_algebra_incdir = include_directories('include')
set_incdir = include_directories('set')

executable('abstract_algebra_test', ['main.cpp'],
  dependencies: [],
  include_directories: [
    abstract_algebra_incdir,
    set_incdir
    ]
  )
