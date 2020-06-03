
from setuptools import setup, find_packages
from itertools  import product

package_name = "dummy"

test_module = ["test"]
test_submodules = find_packages(where=test_module[0])

exclude_modules = []
exclude_modules += test_module
exclude_modules += [".".join(x) for x in product(test_module, test_submodules)]

install_modules = find_packages()
print(install_modules)

package_modules = {}
for fly in install_modules:
  python_path = package_name + "."+fly
  relative_file_path = "./" + fly.replace(".","/")
  package_modules[python_path] = relative_file_path

print(package_modules)

setup(
  name = package_name,
  version = '0.0.0',
  description = 'package to show package path manipulation',
  packages = package_modules.keys(),
  package_dir = package_modules,
  zip_safe = False,
  install_requires = [],
)
