git clone https://github.com/GDTEngine/gdtengine.github.io

echo "Removing current doxygen documentation..."
rm -rf gdtengine.github.io/cppdoc

// echo 'Generating doxygen code documentation...'
// doxygen DoxygenConfig.log
// 
// cd gdtengine.github.io/cppdoc

git commit -a -m "Cpp Documentation."
git push

cd ..

echo "Removing gdtengine.github.io..."
rm -rf gdtengine.github.io