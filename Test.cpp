/**
 *
 * AUTHORS: yuval yahod
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
using namespace ariel;
#include <fstream>
#include <sstream>
//#include <stdexcept>
#include <string>
#include <algorithm>
using namespace std;

//chack operator + 
TEST_CASE("check operator + on km, m, cm"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0 ;
    NumberWithUnits a{len, "km"};
    sum = len *100000;
    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    sum = sum + len *100;
    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    sum = sum +len;
    ////////////////////////
    NumberWithUnits abc = a+b+c;
    CHECK(abc == NumberWithUnits{sum, "cm"});
  
    

}
TEST_CASE("check operator + om g, kg, ton"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0;
    NumberWithUnits d{len, "kg"};
    len = rand() % 1000;
    sum = len * 1000;
    NumberWithUnits e{len, "g"};
    len = rand() % 1000;
    sum +=len;
    NumberWithUnits f{len, "ton"};
    sum += len * 1000000;
    NumberWithUnits def = d+e+f;
    // CHECK_NO_THROW(d+e);
    // CHECK_NO_THROW(d+f);
    // CHECK_NO_THROW(e+f);
    CHECK(def == NumberWithUnits{sum, "g"});
}

TEST_CASE("operator + on hour, min , sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 24;
    int sum = 0 ;
    NumberWithUnits g{len, "hour"};
    len = rand() % 60;
    sum = len *1200;
    NumberWithUnits h{len, "min"};
    len = rand() % 60;
    sum += len *  60;
    NumberWithUnits i{len, "sec"};
    sum +=len;
    NumberWithUnits ghi = g+h+i;
    // CHECK_NO_THROW(g+h);
    // CHECK_NO_THROW(g+i);
    // CHECK_NO_THROW(i+h);
    CHECK(ghi == NumberWithUnits{sum, "sec"});
}

///
//chack operator - 
TEST_CASE("check operator - on km, m, cm"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0 ;
    NumberWithUnits a{len, "km"};
    sum = len *100000;
    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    sum = sum - len *100;
    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    sum = sum - len;
    ////////////////////////
    NumberWithUnits abc = a-b-c;
    // CHECK_NO_THROW(a-b);
    // CHECK_NO_THROW(a-c);
    // CHECK_NO_THROW(b-c);
    CHECK(abc == NumberWithUnits{sum, "cm"});

}
TEST_CASE("check operator - om g, kg, ton"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0;
    NumberWithUnits d{len, "kg"};
    len = rand() % 1000;
    sum = len * 1000;
    NumberWithUnits e{len, "g"};
    len = rand() % 1000;
    sum -=len;
    NumberWithUnits f{len, "ton"};
    sum -= len * 1000000;
    NumberWithUnits def = d-e-f;
    // CHECK_NO_THROW(d-e);
    // CHECK_NO_THROW(d-f);
    // CHECK_NO_THROW(e-f);
    CHECK(def == NumberWithUnits{sum, "g"});
}
TEST_CASE("operator - on hour, min , sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 24;
    int sum = 0 ;
    NumberWithUnits g{len, "hour"};
    len = rand() % 60;
    sum = len *1200;
    NumberWithUnits h{len, "min"};
    len = rand() % 60;
    sum -= len *  60;
    NumberWithUnits i{len, "sec"};
    sum -=len;
    NumberWithUnits ghi = g-h-i;
    // CHECK_NO_THROW(g-h);
    // CHECK_NO_THROW(g-i);
    // CHECK_NO_THROW(i-h);
    CHECK(ghi == NumberWithUnits{sum, "sec"});
}

//chack operator += 
TEST_CASE("check operator += on km, m, cm"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0 ;
    NumberWithUnits a{len, "km"};
    sum = len *100000;
    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    sum = sum + len *100;
    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    sum = sum +len;
    ////////////////////////
    NumberWithUnits abc{0 , "cm"};
    // CHECK_NO_THROW(abc+=a);
    // CHECK_NO_THROW(abc+=b);
    // CHECK_NO_THROW(bbc+=c);
    CHECK(abc == NumberWithUnits{sum, "cm"});

}
TEST_CASE("check operator += on g, kg, ton"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0;
    NumberWithUnits d{len, "kg"};
    len = rand() % 1000;
    sum = len * 1000;
    NumberWithUnits e{len, "g"};
    len = rand() % 1000;
    sum +=len;
    NumberWithUnits f{len, "ton"};
    sum += len * 1000000;
    NumberWithUnits def{0 , "g"};
    // CHECK_NO_THROW(def+=d);
    // CHECK_NO_THROW(def+=e);
    // CHECK_NO_THROW(def+=f);
    CHECK(def == NumberWithUnits{sum, "g"});
}
TEST_CASE("operator += on hour, min , sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 24;
    int sum = 0 ;
    NumberWithUnits g{len, "hour"};
    len = rand() % 60;
    sum = len *1200;
    NumberWithUnits h{len, "min"};
    len = rand() % 60;
    sum += len *  60;
    NumberWithUnits i{len, "sec"};
    sum +=len;
    NumberWithUnits ghi{ 0 , "sec"};
    // CHECK_NO_THROW(ghi+=g);
    // CHECK_NO_THROW(ghi+=h);
    // CHECK_NO_THROW(ghi+=i);
    CHECK(ghi == NumberWithUnits{sum, "sec"});
}

//chack operator += 
TEST_CASE("check operator -= on km, m, cm"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0 ;
    NumberWithUnits a{len, "km"};
    sum = len *100000;
    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    sum = sum + len *100;
    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    sum = sum +len;
    ////////////////////////
    NumberWithUnits abc{sum , "cm"};
    // CHECK_NO_THROW(abc-=a);
    // CHECK_NO_THROW(abc-=b);
    // CHECK_NO_THROW(bbc-=c);
    CHECK(abc == NumberWithUnits{0, "cm"});

}
TEST_CASE("check operator -= on g, kg, ton"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    int sum = 0;
    NumberWithUnits d{len, "ton"};
    len = rand() % 1000;
    sum =len *1000000;
    NumberWithUnits e{len, "kg"};
    len = rand() % 1000;
    sum+=len*1000;
    NumberWithUnits f{len, "g"};
    sum+=len;
    NumberWithUnits def{ sum , "g"};
    def-=e;
    def-=f;
    // CHECK_NO_THROW(def-=d);
    // CHECK_NO_THROW(def-=e);
    // CHECK_NO_THROW(def-=f);
    CHECK( d==def);
}
TEST_CASE("operator -= on hour, min , sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 24;
    int sum = 0 ;
    NumberWithUnits g{len, "hour"};
    len = rand() % 60;
    sum = len *1200;
    NumberWithUnits h{len, "min"};
    len = rand() % 60;
    sum -= len *  60;
    NumberWithUnits i{len, "sec"};
    sum -=len;
    NumberWithUnits ghi{ sum , "sec"};
    // CHECK_NO_THROW(ghi-=g);
    // CHECK_NO_THROW(ghi-=h);
    // CHECK_NO_THROW(ghi-=i);
    ghi-=h;
    ghi-=i;
    CHECK(ghi == g);
}
TEST_CASE("operator + onari  "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    NumberWithUnits a{len, "km"};
    CHECK(a == +a);
    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    CHECK(b == +b);
    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    CHECK(c == +c);
    len = rand() % 1000;
    NumberWithUnits d{len, "kg"};
    CHECK(d == +d);
    len = rand() % 1000;
    NumberWithUnits e{len, "g"};
    CHECK(e == +e);
    len = rand() % 1000;
    NumberWithUnits f{len, "ton"};
    CHECK(f == +f);
    len = rand() % 24;
    NumberWithUnits g{len, "hour"};
    CHECK(g == +g);
    len = rand() % 60;
    NumberWithUnits h{len, "min"};
    CHECK(h == +h);
    len = rand() % 60;
    NumberWithUnits i{len, "sec"};
    CHECK(i == +i);
}
TEST_CASE("operator - onari  "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int len = rand() % 1000;
    NumberWithUnits a{len, "km"};
    CHECK(-a == NumberWithUnits{-len, "km"});

    len = rand() % 1000;
    NumberWithUnits b{len, "m"};
    CHECK(-b == NumberWithUnits {-len, "m"});

    len = rand() % 1000;
    NumberWithUnits c{len, "cm"};
    CHECK(-c == NumberWithUnits {-len, "cm"});

    len = rand() % 1000;
    NumberWithUnits d{len, "kg"};
    CHECK(-d == NumberWithUnits {-len, "kg"});

    len = rand() % 1000;
    NumberWithUnits e{len, "g"};
    CHECK(-e == NumberWithUnits {-len, "g"});

    len = rand() % 1000;
    NumberWithUnits f{len, "ton"};
    CHECK(-f == NumberWithUnits {-len, "ton"});

    len = rand() % 24;
    NumberWithUnits g{len, "hour"};
    CHECK(-g == NumberWithUnits {-len, "hour"});
    
    len = rand() % 60;
    NumberWithUnits h{len, "min"};
    CHECK(-h == NumberWithUnits {-len, "min"});

    len = rand() % 60;
    NumberWithUnits i{len, "sec"};
    CHECK(-i == NumberWithUnits {-len, "sec"});
}

TEST_CASE("operator < , <= , > , >= , == , != : on m. km.cm"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{2000, "m"};
    NumberWithUnits c{200000, "cm"};
    CHECK(a == b);
    CHECK(a == c);
    CHECK(c == b);
    NumberWithUnits a1{2003, "m"};
    NumberWithUnits b1{200004, "cm"};
    CHECK(a < a1);
    CHECK(a < b1);

    CHECK(a <= a1);
    CHECK(a <= b1);
    CHECK(a <= c);
    NumberWithUnits a2{1999, "m"};
    NumberWithUnits b2{199994, "cm"};
    CHECK(a > a2);
    CHECK(a > b2);

    CHECK(a >= a1);
    CHECK(a >= b1);
    CHECK(a >= c);

    NumberWithUnits a3{2003, "m"};
    NumberWithUnits b3{200004, "cm"};
    CHECK(a < a3);
    CHECK(a < b3);

    CHECK(a != a3);
    CHECK(a != b3);

}
TEST_CASE("operator < , <= , > , >= , == , != : on g. kg , ton"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "ton"};
    NumberWithUnits b{2000, "kg"};
    NumberWithUnits c{2000000, "g"};
    CHECK(a == b);
    CHECK(a == c);
    CHECK(c == b);
    NumberWithUnits a1{2003, "kg"};
    NumberWithUnits b1{2000004, "g"};
    CHECK(a < a1);
    CHECK(a < b1);

    CHECK(a <= a1);
    CHECK(a <= b1);
    CHECK(a <= c);
    NumberWithUnits a2{1999, "kg"};
    NumberWithUnits b2{1999994, "g"};
    CHECK(a > a2);
    CHECK(a > b2);

    CHECK(a >= a1);
    CHECK(a >= b1);
    CHECK(a >= c);

    NumberWithUnits a3{2003, "kg"};
    NumberWithUnits b3{2000004, "g"};

    CHECK(a != a3);
    CHECK(a != b3);

}
TEST_CASE("operator < , <= , > , >= , == , != : on hour ,  min ,sec"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{120, "min"};
    NumberWithUnits c{120*60, "sec"};
    CHECK(a == b);
    CHECK(a == c);
    CHECK(c == b);
    NumberWithUnits a1{121, "min"};
    NumberWithUnits b1{120*60 +1, "sec"};
    CHECK(a < a1);
    CHECK(a < b1);

    CHECK(a <= a1);
    CHECK(a <= b1);
    CHECK(a <= c);
    NumberWithUnits a2{110, "m"};
    NumberWithUnits b2{120*60 -10, "cm"};
    CHECK(a > a2);
    CHECK(a > b2);

    CHECK(a >= a1);
    CHECK(a >= b1);
    CHECK(a >= c);

    CHECK(a != a2);
    CHECK(a != b2);

}
TEST_CASE("operator x-- "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{120, "min"};
    CHECK(a != b);
    for(int i = 0 ; i < 60 ; i++){
        b--;
    }
    CHECK(a == b);

    NumberWithUnits c{1, "km"};
    NumberWithUnits d{2000, "m"};
    CHECK(c != d);
    for(int i = 0 ; i < 1000 ; i++){
        d--;
    }
    CHECK(c == d);

    NumberWithUnits e{1, "ton"};
    NumberWithUnits f{2000, "kg"};
    CHECK(e != f);
    for(int i = 0 ; i < 1000 ; i++){
        f--;
    }
    CHECK(e == f);

}


TEST_CASE("operator --x "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{60, "min"};
    CHECK(a != b);
    CHECK(--a == b);

    NumberWithUnits c{3, "km"};
    NumberWithUnits d{2000, "m"};
    CHECK(c != d);
    CHECK(--c == d);

    NumberWithUnits e{2, "ton"};
    NumberWithUnits f{1000, "kg"};
    CHECK(e != f);
    CHECK(--e == f);

}

TEST_CASE("operator x++ "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "hour"};
    NumberWithUnits b{60, "min"};
    CHECK(a != b);
    for(int i = 0 ; i < 60 ; i++){
        b++;
    }
    CHECK(a == b);

    NumberWithUnits c{2, "km"};
    NumberWithUnits d{1000, "m"};
    CHECK(c != d);
    for(int i = 0 ; i < 1000 ; i++){
        d++;
    }
    CHECK(c == d);

    NumberWithUnits e{2, "ton"};
    NumberWithUnits f{1000, "kg"};
    CHECK(e != f);
    for(int i = 0 ; i < 1000 ; i++){
        f++;
    }
    CHECK(e == f);

}

TEST_CASE("operator ++x "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{1, "hour"};
    NumberWithUnits b{120, "min"};
    CHECK(a != b);
    CHECK(++a == b);

    NumberWithUnits c{1, "km"};
    NumberWithUnits d{2000, "m"};
    CHECK(c != d);
    CHECK(++c == d);

    NumberWithUnits e{1, "ton"};
    NumberWithUnits f{2000, "kg"};
    CHECK(e != f);
    CHECK(++e == f);
}/*
TEST_CASE("operator NumberWithUnits * double"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    int a1 =rand()%1000 , b1 = rand()%1000 , c1= rand()%1000;
    NumberWithUnits a{a1, "km"};
    NumberWithUnits b{b1, "m"};
    NumberWithUnits c{c1, "cm"};
    double oper = rand()%1000;
    NumberWithUnits a_double = oper * a;
    NumberWithUnits b_double = oper * b;
    NumberWithUnits c_double = oper * c;
    CHECK(a_double == NumberWithUnits{a1 * oper,"km"});
    CHECK(b_double == NumberWithUnits{b1 * oper,"m"});
    CHECK(c_double == NumberWithUnits{c1 * oper,"cm"});

    int d1 =rand()%1000 , e1 = rand()%1000 , f1= rand()%1000;
    NumberWithUnits d{d1, "g"};
    NumberWithUnits e{e1, "kg"};
    NumberWithUnits f{f1, "ton"};
    oper = rand()%1000;
    NumberWithUnits d_double = oper * d;
    NumberWithUnits e_double = oper * e;
    NumberWithUnits f_double = oper * f;
    CHECK(d_double == NumberWithUnits{d1 * oper,"g"});
    CHECK(e_double == NumberWithUnits{e1 * oper,"kg"});
    CHECK(f_double == NumberWithUnits{f1 * oper,"ton"});
}
*/
TEST_CASE("check operator << (os) and >>(is) "){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a;
    istringstream iss_a("2[km]");
    iss_a >> a;
    ostringstream oss_a;
    oss_a << a ;
    CHECK(oss_a.str() == "2[km]");
    
    NumberWithUnits b;
    istringstream iss_b("2000[m]");
    iss_b >> b;
    ostringstream oss_b;
    oss_b << b ;
    CHECK(oss_b.str() == "2000[m]");

    NumberWithUnits c;
    istringstream iss_c("20[cm]");
    iss_c >> c;
    ostringstream oss_c;
    oss_c << c ;
    CHECK(oss_c.str() == "20[m]");

    NumberWithUnits d;
    istringstream iss_d("100[g]");
    iss_d >> d;
    ostringstream oss_d;
    oss_d << d ;
    CHECK(oss_d.str() == "100[g]");

    NumberWithUnits e;
    istringstream iss_e("20[kg]");
    iss_e >> e;
    ostringstream oss_e;
    oss_e << e ;
    CHECK(oss_e.str() == "20[kg]");

    NumberWithUnits f;
    istringstream iss_f("19[ton]");
    iss_f >> f;
    ostringstream oss_f;
    oss_f << f ;
    CHECK(oss_f.str() == "19[ton]");

    NumberWithUnits g;
    istringstream iss_g("12[hour]");
    iss_g >> g;
    ostringstream oss_g;
    oss_g << g ;
    CHECK(oss_g.str() == "12[hour]");

    NumberWithUnits h;
    istringstream iss_h("30[min]");
    iss_h >> h;
    ostringstream oss_h;
    oss_h << h ;
    CHECK(oss_h.str() == "30[min]");
    

}
TEST_CASE(" check the + - == != < > <= >= on not the same units"){
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{2, "km"};
    NumberWithUnits b{20, "m"};
    NumberWithUnits c{200, "cm"};
    NumberWithUnits d{2, "kg"};
    NumberWithUnits e{100, "g"};
    NumberWithUnits f{1, "ton"};
    NumberWithUnits g{10, "hour"};
    NumberWithUnits h{30, "min"};
    NumberWithUnits i{40, "sec"};
    CHECK_THROWS(a+d);
    CHECK_THROWS(a+e);
    CHECK_THROWS(a-f);
    CHECK_THROWS(a-g);
    // CHECK_THROWS(a<h);
    // CHECK_THROWS(a<i);
    // CHECK_THROWS(d<=d);
    // CHECK_THROWS(b<=e);
    // CHECK_THROWS(b>f);
    // CHECK_THROWS(d>=g);
    // CHECK_THROWS(b!=h);
    // CHECK_THROWS(b==i);

}
