             
tmp=make_archive_temp

function die {
  echo $*
  rm -rf $tmp
  exit 1     
}

if [ -d $tmp ] ; then
  echo "there is $tmp!"
  exit
fi


pushd .. || die 'what?'
taskname=`pwd`
taskname=`basename $taskname`
popd || die 'what?'
echo $taskname
                           
mkdir $tmp || die "can't make $tmp"

cp compile_cpp.sh $tmp || die "can't find one of go.sh"
cp grader.cpp $tmp || die "can't find one of graders"
cp $taskname.{h,cpp} $tmp || die "can't find one of sample solutions"



for i in `ls {0..9}{0..9}{0..9} {0..9}{0..9} 2>/dev/null` ; do
   cp $i $i.a $tmp || die "can't copy $i $i.a"
done

pushd $tmp || die "what?"
sed -e '/\/\/ BEGIN_USER_CUT/,/\/\/ END_USER_CUT/d' -i grader.cpp || die "what?"

mkdir $taskname || die "what?"


for i in *; do
    if [ -d $i ] ; then
       continue;
    fi
    mv $i $taskname 
done

tar -czf $taskname.tar.gz $taskname || die "can't tar?"
mv $taskname.tar.gz ..

popd || die "what?"

rm -rf $tmp
