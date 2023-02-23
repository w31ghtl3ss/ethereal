project(
    'ethereal',
    'c',
    default_options: [
        'c_std=c99',
        'warning_level=2',
        'werror=true'
    ]
)

cc = meson.get_compiler('c')
ethereal_inc = include_directories('include')

# dependencies
thread_dep = dependency('threads')

subdir('proxy')
