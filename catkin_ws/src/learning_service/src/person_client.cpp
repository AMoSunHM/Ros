#include<ros/ros.h>
#include"learning_service/Person.h"

int main(int argc,char** argv)
{
  ros::init(argc,argv,"person_clent");
  ros::NodeHandle node;

  ros::service::waitForService("/show_person");
  ros::ServiceClient person_client=
      node.serviceClient<learning_service::Person>("/show_person");

  learning_service::Person srv;
  srv.request.name="tom";
  srv.request.age=20;
  srv.request.sex=learning_service::Person::Request::male;

  ROS_INFO("call service to show person[name:%s,age:%d,sex:%d]",
           srv.request.name.c_str(),srv.request.age,srv.request.sex);

  person_client.call(srv);

  ROS_INFO("show person result: %s",srv.response.result.c_str());

  return 0;
}
