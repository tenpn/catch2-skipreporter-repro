set_languages("c++14")
add_requires("catch2 3.7.0")

target("binary")
  add_packages("catch2")
  add_files("src/*.cpp")
  add_headerfiles("src/*.h")