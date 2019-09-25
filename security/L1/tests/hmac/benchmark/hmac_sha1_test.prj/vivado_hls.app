<project xmlns="com.autoesl.autopilot.project" name="hmac_sha1_test.prj" top="aes256CbcEncryptKernel_1">
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow name="csim" ldflags="-lcrypto -lssl" mflags="" csimMode="0" lastCsimMode="0" setup="false" optimizeCompile="false" clean="false"/>
    </Simulation>
    <includePaths xmlns=""/>
    <libraryFlag xmlns=""/>
    <files xmlns="">
        <file name="../../main.cpp" sc="0" tb="1" cflags=" -I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include -Wno-unknown-pragmas" blackbox="false"/>
        <file name="test.cpp" sc="0" tb="false" cflags="-I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status=""/>
    </solutions>
</project>

