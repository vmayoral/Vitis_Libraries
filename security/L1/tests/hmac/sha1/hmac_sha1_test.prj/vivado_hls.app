<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="hmac_sha1_test.prj" top="test_hmac_sha1">
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="false" ldflags="-lcrypto -lssl" mflags=""/>
    </Simulation>
    <includePaths/>
    <libraryFlag/>
    <files>
        <file name="../../test.cpp" sc="0" tb="1" cflags=" -I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="test.cpp" sc="0" tb="false" cflags="-I/wrk/xsjhdnobkup4/tuol/xf_security//L1/include" csimflags="" blackbox="false"/>
    </files>
    <solutions>
        <solution name="solution1" status=""/>
    </solutions>
</AutoPilot:project>

