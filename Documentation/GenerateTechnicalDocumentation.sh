echo "Removing current doxygen documentation..."
rm -rf cppdoc

echo 'Generating doxygen code documentation...'
doxygen DoxygenConfig.log