proxy_sources = [
    'main.c'
]

executable(
    'ethereal',
    proxy_sources,
    include_directories: [ethereal_inc],
    dependencies: [thread_dep],
    link_with: [lib_data_struct, lib_network],
    install: true
)
