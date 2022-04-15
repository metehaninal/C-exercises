#include<iostream>
#include<string>
#include<vector>


using namespace std;

struct Car
{
   string Model;
   int km ;

   Car(string newModel , int count){
       this->Model = newModel;
       this->km = count;
   }

};
struct MyGarage
{
    vector<Car> v;

    void operator +=(Car& car_obj){
        this->v.push_back(car_obj);
    }
    void operator -=(Car& car){
        //vec.erase(find(vec.begin(),vec.end(),value));
        //this->v.erase(find(v.begin(),v.end(),car));
    }
};

/*void operator<<(ostream& new_cout , Car& car_obj){
    new_cout <<"Model:" << car_obj.Model << endl;
    new_cout <<"Subs:" << car_obj.km << endl;

}
*/
ostream& operator<<(ostream& new_cout , Car& car_obj){
    new_cout <<"Model:" << car_obj.Model << endl;
    new_cout <<"KM:" << car_obj.km << endl;
    return new_cout;
}
ostream& operator<<(ostream& COUT,MyGarage& garage ){
    for (Car cars : garage.v)
    {
        COUT << cars << endl;
    }
    
}
int main(){

    Car car1 = Car("Volvo xc90",25000);
    //cout << car1;
    Car car2 = Car("Wolkswagen Passat",28750);
    Car car3("Nissan Skyline",12341);
    // cout << car1 << car2 does not work if operator overloading function's
    // return type is void. it should be return ostream or whatever.
    //cout << car1 << car2;
    MyGarage mycars;
    mycars += car1;
    mycars += car2;
    mycars += car3;
    //mycars -= car1;
    cout << mycars;

    return 0;
}