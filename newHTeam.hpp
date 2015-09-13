#ifndef HTEAM_INCLUDED
#define HTEAM_INCLUDED
#include"newTeam.hpp"
#include"string"
#include"cctype"

#define BIGOBJ 4
//shao yu zhe ge shu zi  sense di tu

#define debug false
#define STAGE1 false

#define DOALL false
//DOALL 当有1个以上的物品符合任务要求时   为false时 任务只做一个符合要求的物品    true时 所有物品都会被执行

#define ONLY_ONE_CONTAINER false
//对于putin这些动作  为true时 如果有多个容器符合要求 则放弃  为false 时 如果有多个容器符合要求 则选择一个放入

#define NEWPLAN true
//true时 未sense到需要的物品return -10

#define ACTIONCOST 2
#define MOVECOST 4
#define SENSECOST 1
bool isdigit(string str)
{
    bool is_digit=true;
    for(auto& c:str)
    {
        if(!isdigit(c))
        {
            is_digit=false;
        }
        break;
    }
    return is_digit;
}
namespace myplan
{

}
using namespace myplan;
using namespace _home;

/*class Object start*/
bool Object::compare(Object& obj)
{
    //sort color size type
    if(name!=obj.name&&name!="")
    {
        return false;
    }
    if(color!=obj.color&&color!=65535)
    {
        return false;
    }
    if(size!=obj.size&&size!=65535)
    {
        return false;
    }
    if(type!=obj.type&&type!="")
    {

        return false;
    }
    return true;
}

/*class Object end  */


/*class stringHandler start*/
string myplan::stringHandler::cond(string str)
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=str.find("(:cond "))==string::npos)
        return "";
    for(int i=startFlag;str[i]!='\0';i++)
    {
        len++;
        if(str[i]=='(')
            numBrackets++;
        else if(str[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(str,startFlag,len);
    return result;
}
string myplan::stringHandler::info(string str)
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=str.find("(:info "))==string::npos)
        return "";
    for(int i=startFlag;str[i]!='\0';i++)
    {
        len++;
        if(str[i]=='(')
            numBrackets++;
        else if(str[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(str,startFlag,len);

    return result;
}
string myplan::stringHandler::cons_not()
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=insString.find("(:cons_not "))==string::npos)
        return "";
    for(int i=startFlag;insString[i]!='\0';i++)
    {
        len++;
        if(insString[i]=='(')
            numBrackets++;
        else if(insString[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(insString,startFlag,len);
    if(insString[startFlag-1]==' ')
        startFlag--,len++;
    insString.erase(startFlag,len);
    return result;
}
string myplan::stringHandler::cons_notnot()
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=insString.find("(:cons_notnot "))==string::npos)
        return "";
    for(int i=startFlag;insString[i]!='\0';i++)
    {
        len++;
        if(insString[i]=='(')
            numBrackets++;
        else if(insString[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(insString,startFlag,len);
    if(insString[startFlag-1]==' ')
        startFlag--,len++;
    insString.erase(startFlag,len);
    return result;
}
string myplan::stringHandler::info()
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=insString.find("(:info "))==string::npos)
        return "";
    for(int i=startFlag;insString[i]!='\0';i++)
    {
        len++;
        if(insString[i]=='(')
            numBrackets++;
        else if(insString[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(insString,startFlag,len);
    if(insString[startFlag-1]==' ')
        startFlag--,len++;
    insString.erase(startFlag,len);


    return result;
}
string myplan::stringHandler::task()
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=insString.find("(:task "))==string::npos)
        return "";
    for(int i=startFlag;insString[i]!='\0';i++)
    {
        len++;
        if(insString[i]=='(')
            numBrackets++;
        else if(insString[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(insString,startFlag,len);
    if(insString[startFlag-1]==' ')
        startFlag--,len++;
    insString.erase(startFlag,len);



    return result;
}
string myplan::stringHandler::task(string str)
{
    string result("");
    int len=0;
    int startFlag=0;
    int numBrackets=0;
    if((startFlag=str.find("(:task "))==string::npos)
        return "";
    for(int i=startFlag;str[i]!='\0';i++)
    {
        len++;
        if(str[i]=='(')
            numBrackets++;
        else if(str[i]==')')
            numBrackets--;
        if(numBrackets==0)
            break;
    }
    result.append(str,startFlag,len);

    return result;
}

void myplan::stringHandler::GetIns(string ins)
{
    insString=ins;
}
/*class stringHandler end   */

/*class myTask start*/
int myplan::myTask::ActionToInt(string actionStr)
{
    if(actionStr=="give")
        return 1;

    else if(actionStr=="puton")
        return 2;

    else if(actionStr=="goto")
        return 3;

    else if(actionStr=="putdown")
        return 4;

    else if(actionStr=="pickup")
        return 5;

    else if(actionStr=="open")
        return 6;

    else if(actionStr=="putin")
        return 7;

    else if(actionStr=="close")
        return 8;

    else if(actionStr=="takeout")
        return 9;

    else
    {
        cout<<"action error"<<endl;
        cout<<actionStr<<endl;
        return 0;
    }

}
/*class myTask end  */

/*class function start*/
unsigned int myplan::function::ColorToInt(string str)    //物体颜色：0：无，1：white,2:red,3:green,4:yellow,5:blue,6:black
{
    unsigned int result;


    if(str=="white")
    {
        result=1;
    }
    else if(str=="red")
    {
        result=2;
    }
    else if(str=="green")
    {
        result=3;
    }
    else if(str=="yellow")
    {
        result=4;
    }
    else if(str=="blue")
    {
        result=5;
    }
    else if(str=="black")
    {
        result=6;
    }
    else
    {
        result=0;
        if(debug)
            cout<<"color error"<<endl;
    }
    return result;
}

unsigned int myplan::function::SizeToInt(string str)
{
    unsigned int result;
    if("small"==str)
    {
        result=1;
    }
    else if("big"==str)
    {
        result=2;
    }
    else
    {
        result=0;
        if(debug)
            cout<<"size error"<<endl;
    }

    return result;
}

unsigned int myplan::function::DoorToInt(string str)
{
    unsigned int result;
    if("opened"==str)
    {
        result=1;
    }
    else if("closed"==str)
    {
        result=2;
    }
    else
    {
        result=0;
        if(debug)
            cout<<"door error"<<endl;
    }

    return result;
}
/*class function end  */


/*class ObjectList start*/


    void myplan::ObjectList::EnvHandler(string Env)
    {
        Object *item;
        bool flag;
        bool isInt;//1 true tempInt有内容   2 false tempVar有内容
        //bool isTempStrInt;//1 true tempInt2有内容 2 false tempString 有内容
        unsigned int tempInt;//存放获取整数
        string tempVar;
        string temp;                                //存放正则表达式获取内容
        string tempString;//存放获取字符串
        string regStrP1;
        string regStrP2;
        std::vector<string> regPart1;
        regPart1.push_back("sort");
        regPart1.push_back("color");
        regPart1.push_back("size");
        regPart1.push_back("type");

        regPart1.push_back("at");
        regPart1.push_back("inside");
        regPart1.push_back("on");
        regPart1.push_back("near");

        regPart1.push_back("opened");
        regPart1.push_back("closed");

        regPart1.push_back("hold");
        regPart1.push_back("plate");

        boost::regex regP1;
        boost::regex regP2;
        boost::sregex_token_iterator itrEnd;
        boost::smatch mat;


        for(vector<string>::iterator its=regPart1.begin();its!=regPart1.end();its++)
        {
            regStrP1="\\("+(*its)+"[^\\)]+\\)";

            regP1=boost::regex(regStrP1,boost::regex_constants::nosubs);
            for(boost::sregex_token_iterator itr(Env.begin(),Env.end(),regP1);itr!=itrEnd;itr++)
            {
                if((*its)=="plate"||(*its)=="hold"||(*its)=="opened"||(*its)=="closed")
                {
                    regStrP2="(?<=\\s)[^\\s\\)]+(?=\\))";
                }
                else
                {
                    regStrP2="(?<=\\s)[^\\s\\)]+(?=\\s)";
                }

                regP2=boost::regex(regStrP2);

                temp=*itr;
                tempString=getTempString(temp);
                boost::regex_search(temp,mat,regP2);
                temp=mat[0];


                if(temp.empty())
                    continue;
                if(isdigit(temp))
                {
                    tempInt=stoi(temp);

                    isInt=true;
                }
                else
                {
                    tempVar=temp;
                    isInt=false;
                }


                if(*its=="sort")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {

                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).name=tempString;
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                (*it).name=tempString;
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();

                        if(true==isInt)
                            item->id=tempInt;
                        else
                            item->id_str=tempVar;

                        item->name=tempString;
                        obj.push_back(*item);
                        delete item;
                    }
                    //working
                }
                else if(*its=="color")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).color=ColorToInt(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                (*it).color=ColorToInt(tempString);
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                            item->id=tempInt;
                        else
                            item->id_str=tempVar;

                        item->color=ColorToInt(tempString);
                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if(*its=="size")
                {

                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).size=SizeToInt(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                (*it).size=SizeToInt(tempString);
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                            item->id=tempInt;
                        else
                            item->id_str=tempVar;

                        item->size=SizeToInt(tempString);
                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if(*its=="type")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).type=tempString;
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                (*it).type=tempString;
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                            item->id=tempInt;
                        else
                            item->id_str=tempVar;
                        item->type=tempString;
                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if(*its=="at")
                {
                    flag=false;
                    if(tempInt==0&&true==isInt)
                    {
                        bot.loc=stoi(tempString);
                        flag=true;
                    }
                    else
                    {
                        for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                        {
                            if(true==isInt)
                            {
                                if((*it).id==tempInt)
                                {
                                    flag=true;
                                    (*it).location=stoi(tempString);
                                }
                            }
                            else if(false==isInt)
                            {
                                if((*it).id_str==tempVar)
                                {
                                    flag=true;
                                    it->is_on_str=tempString;
                                    //(*it).location_str=tempString;
                                }
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();

                        if(true==isInt)
                        {
                            item->id=tempInt;
                            item->location=stoi(tempString);
                        }
                        else
                        {
                            item->id_str=tempVar;
                            item->is_on_str=tempString;
                            //item->location_str=tempString;
                        }

                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if(*its=="inside")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                it->is_inside=stoi(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                it->is_inside_str=tempString;
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=tempInt;
                            item->is_inside=stoi(tempString);
                        }
                        else
                        {
                            item->id_str=tempVar;
                            item->is_inside_str=tempString;
                        }

                        obj.push_back(*item);
                        delete item;
                    }

                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==stoi(tempString))
                            {
                                flag=true;
                                it->inside_id.push_back(tempInt);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempString)
                            {
                                flag=true;
                                it->inside_id_str.push_back(tempVar);
                            }
                        }

                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=stoi(tempString);
                            item->inside_id.push_back(tempInt);
                        }
                        else
                        {
                            item->id_str=tempString;
                            item->inside_id_str.push_back(tempVar);
                        }

                        obj.push_back(*item);
                        delete item;
                    }

                }
                else if(*its=="on")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                //(*it).on_id=stoi(tempString);
                                //it->on_id.push_back(stoi(tempString));
                                it->is_on=stoi(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                //(*it).on_id_str=tempString;
                                //it->on_id_str.push_back(tempString);
                                it->is_on_str=tempString;
                            }
                        }

                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=tempInt;
                            //item->on_id=stoi(tempString);
                            //item->on_id.push_back(stoi(tempString));
                            item->is_on=stoi(tempString);
                        }
                        else
                        {
                            item->id_str=tempVar;
                            //item->on_id_str=tempString;
                            //item->on_id_str.push_back(tempString);
                            item->is_on_str=tempString;
                        }
                        obj.push_back(*item);
                        delete item;
                    }

                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==stoi(tempString))
                            {
                                flag=true;
                                (*it).on_id.push_back(tempInt);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempString)
                            {
                                flag=true;
                                (*it).on_id_str.push_back(tempVar);
                            }
                        }

                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=stoi(tempString);
                            item->on_id.push_back(tempInt);
                        }
                        else
                        {
                            item->id_str=tempString;
                            item->on_id_str.push_back(tempVar);
                        }
                        obj.push_back(*item);
                        delete item;
                    }

                }
                else if(*its=="near")
                {
                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).near.push_back(stoi(tempString));
                                //(*it).near=stoi(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempVar)
                            {
                                flag=true;
                                it->near_str.push_back(tempString);
                                //it->near_str=tempString;
                            }
                        }

                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=tempInt;
                            item->near.push_back(stoi(tempString));
                            //item->near=stoi(tempString);
                        }
                        else
                        {
                            item->id_str=tempVar;
                            item->near_str.push_back(tempString);
                        }

                        obj.push_back(*item);
                        delete item;
                    }

                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==stoi(tempString))
                            {
                                flag=true;
                                (*it).near.push_back(tempInt);
                                //(*it).near=stoi(tempString);
                            }
                        }
                        else if(false==isInt)
                        {
                            if((*it).id_str==tempString)
                            {
                                flag=true;
                                it->near_str.push_back(tempVar);
                                //it->near_str=tempString;
                            }
                        }

                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                        {
                            item->id=stoi(tempString);
                            item->near.push_back(tempInt);
                        }
                        else
                        {
                            item->id_str=tempString;
                            item->near_str.push_back(tempVar);
                        }

                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if((*its=="opened")||(*its=="closed"))
                {

                    flag=false;
                    for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
                    {
                        if(true==isInt)
                        {
                            if((*it).id==tempInt)
                            {
                                flag=true;
                                (*it).is_open=DoorToInt(*its);
                            }
                        }
                        else if(false==isInt)
                        {
                            if(it->id_str==tempVar)
                            {
                                flag=true;
                                it->is_open=DoorToInt(*its);
                            }
                        }
                    }
                    if(false==flag)
                    {
                        item=new Object();
                        if(true==isInt)
                            item->id=tempInt;
                        else
                            item->id_str=tempVar;
                        item->is_open=DoorToInt(*its);
                        obj.push_back(*item);
                        delete item;
                    }
                }
                else if(*its=="hold")
                {
                    if(true==isInt)
                        bot.hold=stoi(tempString);
                    else
                        bot.hold_str=tempString;
                }
                else if(*its=="plate")
                {
                    if(true==isInt)
                        bot.plate=stoi(tempString);
                    else
                        bot.plate_str=tempString;
                }

            }
        }

        //debug cout
    }
//*/

string myplan::ObjectList::getTempString(string regIt)
{
    string result;
    string regStr="(?<=\\s)[^\\s\\)]+(?=\\))";
    boost::smatch mat;
    boost::regex reg(regStr);
    boost::regex_search(regIt,mat,reg);
    if(mat[0].matched)
    {
        result=mat[0];
        return result;
    }
    else return "";
}


/*class ObjectList end  */

/*class taskList start*/
void myplan::taskList::TaskHandler(string Task)
{
    string regStr;
    boost::regex reg;
    boost::regex regP1;
    boost::regex regP2;
    boost::sregex_token_iterator itrEnd;
    boost::smatch mat;

    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;
    stringHandler sh;
    stringHandler sh2;
    sh.GetIns(Task);

    vector<string> sCons_notnotList;
    vector<string> sCons_notList;

    vector<string> sCons_notTask;
    vector<string> sCons_notInfo;
    vector<string> sCons_infoList;
    vector<string> sCons_taskList;
    while((temp=sh.cons_notnot())!="")
    {

        sCons_notnotList.push_back(temp);
    }
    while((temp=sh.cons_not())!="")
    {
        sh2.GetIns(temp);
        while((temp1=sh2.task())!="")
            sCons_notTask.push_back(temp1);
        sh2.GetIns(temp);
        while((temp1=sh2.info())!="")
        {
            sCons_notInfo.push_back(temp);
        }
        //sCons_notList.push_back(temp);
    }
    while((temp=sh.info())!="")
    {
        sCons_infoList.push_back(temp);
    }
    while((temp=sh.task())!="")
    {
        sCons_taskList.push_back(temp);
    }


    getCons_notnotInfo(sCons_notnotList);
    getCons_notInfo(sCons_notInfo);
    getInfo(sCons_infoList);
    getTask(sCons_taskList);
    getCons_notTask(sCons_notTask);
//working
}

void myplan::taskList::getInfo(vector<string>& sCons_infoList)
{
    stringHandler sh;
    string regStr;
    ObjectList* item;


    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;
    for(vector<string>::iterator its=sCons_infoList.begin();its!=sCons_infoList.end();its++)
    {
        item=new ObjectList();
        temp=sh.info(*its);
        ////////////info


        item->EnvHandler(temp);
        info.push_back(*item);
        delete item;
    }
}
void myplan::taskList::getTask(vector<string>& sCons_taskList)
{
    stringHandler sh;
    string regStr;
    boost::regex reg;
    boost::regex regP1;
    //boost::regex regP2;
    boost::sregex_token_iterator itrEnd;
    boost::smatch mat;

    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;



    myTask* itemTask;
    for(vector<string>::iterator its=sCons_taskList.begin();its!=sCons_taskList.end();its++)
    {
        bool flag;
        itemTask=new myTask();
        temp="(?<=\\()(?!(:))[^\\s\\)]+(?=\\s)";
        reg=boost::regex(temp);
        temp=*its;

        if(debug)
            cout<<temp<<endl;

        boost::regex_search(temp,mat,reg);
        temp=mat[0];

        itemTask->action=itemTask->ActionToInt(temp);

        if(debug)
            cout<<temp<<endl;


        temp="(?<=(\\s))\\w+(?!(\\)))";
        reg=boost::regex(temp);
        temp=*its;
        boost::regex_search(temp,mat,reg);
        temp=mat[0];
        itemTask->firstVar=temp;

        if(debug)
            cout<<temp<<endl;



        temp="(?<=(\\s))\\w+(?=(\\)))";
        reg=boost::regex(temp);
        temp=*its;
        boost::regex_search(temp,mat,reg);
        temp=mat[0];
        itemTask->secondVar=temp;

        if(debug)
            cout<<temp<<endl;

        temp=*its;
        temp=sh.cond(temp);

        regStr="\\([^\\(\\)]+\\)";
        reg=boost::regex(regStr);

        //temp

        itemTask->obj.EnvHandler(temp);
        task.push_back(*itemTask);
        delete itemTask;
    }
}
void myplan::taskList::getCons_notInfo(vector<string>& sCons_notInfo)
{
    stringHandler sh;
    string regStr;
    boost::regex reg;
    boost::regex regP1;
    //boost::regex regP2;
    boost::sregex_token_iterator itrEnd;
    boost::smatch mat;

    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;

    ObjectList* item;
    for(vector<string>::iterator its=sCons_notInfo.begin();its!=sCons_notInfo.end();its++)
    {
        item=new ObjectList();
        temp=sh.info(*its);
        ////////////info
        reg=boost::regex("\\((?!(:))[^\\(\\)]+\\)");

        boost::regex_search(*its,mat,reg);

        item->EnvHandler(temp);
        cons_notInfo.push_back(*item);
        delete item;

    }
}
void myplan::taskList::getCons_notnotInfo(vector<string>& sCons_notnotList)
{
    stringHandler sh;
    string regStr;
    boost::regex reg;
    boost::regex regP1;
    //boost::regex regP2;
    boost::sregex_token_iterator itrEnd;
    boost::smatch mat;

    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;

    ObjectList* item;
    for(vector<string>::iterator its=sCons_notnotList.begin();its!=sCons_notnotList.end();its++)
    {
        item=new ObjectList();
        temp=sh.info(*its);
        ////////////info
        reg=boost::regex("\\((?!(:))[^\\(\\)]+\\)");

        boost::regex_search(*its,mat,reg);
        item->EnvHandler(temp);
        cons_notnotInfo.push_back(*item);
        delete item;
    }
}
void myplan::taskList::getCons_notTask(vector<string>& sCons_notTask)
{
    stringHandler sh;
    string regStr;
    boost::regex reg;
    boost::regex regP1;
    //boost::regex regP2;
    boost::sregex_token_iterator itrEnd;
    boost::smatch mat;

    string temp;
    string temp1;//obj赋值时使用
    string tempVal1;
    string tempVal2;
    string itemClass;



    myTask* itemTask;
    for(vector<string>::iterator its=sCons_notTask.begin();its!=sCons_notTask.end();its++)
    {
        itemTask=new myTask();
        temp="(?<=\\()(?!(:))[^\\s\\)]+(?=\\s)";
        reg=boost::regex(temp);
        temp=*its;
        boost::regex_search(temp,mat,reg);
        temp=mat[0];
        //itemTask->actionStr=temp;
        itemTask->action=itemTask->ActionToInt(temp);

        temp=*its;

        if(debug)
            cout<<temp<<endl;

        boost::regex_search(temp,mat,reg);
        temp=mat[0];

        itemTask->action=itemTask->ActionToInt(temp);

        if(debug)
            cout<<temp<<endl;


        temp="(?<=(\\s))\\w+(?!(\\)))";
        reg=boost::regex(temp);
        temp=*its;
        boost::regex_search(temp,mat,reg);
        temp=mat[0];
        itemTask->firstVar=temp;

        if(debug)
            cout<<temp<<endl;



        temp="(?<=(\\s))\\w+(?=(\\)))";
        reg=boost::regex(temp);
        temp=*its;
        boost::regex_search(temp,mat,reg);
        temp=mat[0];
        itemTask->secondVar=temp;

        if(debug)
            cout<<temp<<endl;


        //////////////////
        temp=*its;
        temp=sh.cond(temp);

        regStr="\\([^\\(\\)]+\\)";
        reg=boost::regex(regStr);

        //EnvHandler
        itemTask->obj.EnvHandler(temp);
        cons_notTask.push_back(*itemTask);
        delete itemTask;
    }
}

/*class taskList end  */

/*class command start*/
int TeamName::eMove(unsigned int loc)
{
    bool done=false;
    done=Move(loc);

    return done;
}
int TeamName::ePickUp(unsigned int id)
{
    bool done=false;
    done=PickUp(id);

    return done;
}
int TeamName::ePutDown(unsigned int id)
{
    bool done=false;
    done=PutDown(id);

    return done;
}
int TeamName::eToPlate(unsigned int id)
{
    bool done=false;
    done=ToPlate(id);


    return done;
}
int TeamName::eFromPlate(unsigned int id)
{
    bool done=false;
    done=FromPlate(id);

    return done;
}
int TeamName::eOpen(unsigned int continerId)
{
    bool done=false;
    done=Open(continerId);


    return done;
}
int TeamName::eClose(unsigned int continerId)
{
    bool done=false;
    done=Close(continerId);


    return done;
}
int TeamName::ePutIn(unsigned int objId,unsigned int continerId)
{
    bool done=false;
    done=PutIn(objId,continerId);


    return done;
}
int TeamName::eTakeOut(unsigned int objId,unsigned int continerId)
{
    bool done=false;
    done=TakeOut(objId,continerId);


    return done;
}
string TeamName::eAskLoc(unsigned a)
{
    bool done=false;


    done=true;
    return "";
}


//debug
int TeamName::cGive(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    unsigned int humanId=65535;
    humanId=getObjId_name(objlist,tasklist,"human");
    Object humanObj=getObj_id(objlist,tasklist,humanId);

    string objVar;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=2;

    if(mytask.firstVar!="human")
    {
        objVar=mytask.firstVar;
    }
    else
    {
        objVar=mytask.secondVar;
    }
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,objVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector);


        Object& objX=getObj_id(objlist,tasklist,targetNum.x);
        if(objX!=*Object::NULLObj&&humanObj!=*Object::NULLObj)
        {
            if(objX.location==humanObj.location&&objX.location!=65535)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }


        if(targetNum.x!=65535&&targetNum.y!=65535)
        {
            offset=cPutOn(objlist,tasklist,targetNum.x,targetNum.y,true);
        }
        else
        {
            return -3;
        }

        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum.x)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cGive(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector);
            if(targetNum_Sense.x!=65535)
                targetNum=targetNum_Sense;
            else
            {

            }
            if(targetNum.x!=65535&&targetNum.y!=65535)
            {
                offset=cPutOn(objlist,tasklist,targetNum.x,targetNum.y,true);
            }
            else
            {
                return -3;
            }
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum.x)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cGive(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;

    return offset;
}


//X puton Y
//debug


int TeamName::eSense(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    unsigned int result=0;

    if(STAGE1==true)
    {
        return id;
    }

    if(objlist.bot.loc!=objlist.bot.senseLoc)
    {
        vector<unsigned int> res;
        Sense(res);
        objlist.bot.senseLoc=objlist.bot.loc;
        objlist.bot.here.clear();
        for(vector<unsigned int>::iterator it=res.begin();it!=res.end();it++)
        {
            objlist.bot.here.push_back(*it);
            if(*it==id)
            {
                result=id;
            }
            Object& target=getObj_id(objlist,tasklist,*it);
            if(target!=*Object::NULLObj)
            {
                target.location=objlist.bot.loc;
                getObj_id(objlist,tasklist,*it).sensed=true;
            }
        }
    }
    else if(objlist.bot.loc==objlist.bot.senseLoc)
    {
        for(vector<unsigned int>::iterator it=objlist.bot.here.begin();it!=objlist.bot.here.end();it++)
        {
            if(*it==id)
            {
                result=id;
            }
            Object& target=getObj_id(objlist,tasklist,*it);
            if(target!=*Object::NULLObj)
            {
                target.location=objlist.bot.loc;
            }
        }
    }
    if(0==result)
    {
        Object& target=getObj_id(objlist,tasklist,id);
        //cout<<"xxx"<<endl;
        if(target!=*Object::NULLObj)
        {
            if(target.location==objlist.bot.senseLoc)
            {
                target.location=65535;

            }
        }
    }
    return result;
}

unsigned int TeamName::ChooseObj(ObjectList& objlist,taskList& tasklist,vector<unsigned int> para_vector)
{
    unsigned int result=65535;
    //与自己同位置且被sense到的
        for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,*it);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result=*it;
                break;
            }
        }

        //被sense到的
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result=*it;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;



                if(65535!=firstObj.location)
                {
                    result=*it;
                    break;
                }
            }
        }

        //随便选择一个...
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                result=*it;
                if(result==65535)
                    continue;
                break;
            }
        }
    return result;
}

unsigned int TeamName::ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,vector<unsigned int> para_vector)
{
    unsigned int result=65535;
    //与自己同位置且被sense到的
        for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,*it);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result=*it;
                break;
            }
        }

        //被sense到的
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result=*it;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result=*it;
                    break;
                }
            }
        }
    return result;
}

C_para_2 TeamName::ChooseObj_big(ObjectList& objlist,taskList& tasklist,vector<C_para_2> para_vector)
{
    C_para_2 result;
        //与自己同位置且被sense到的
        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result.x=it->x;
                result.y=it->y;
                break;
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //随便选择一个...
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                result.x=it->x;
                result.y=it->y;
                if(result.x==65535||result.y==65535)
                    continue;
                break;
            }
        }

    return result;
}

C_para_2 TeamName::ChooseObj_big_Sense(ObjectList& objlist,taskList& tasklist,vector<C_para_2> para_vector)
{
    C_para_2 result;
            //与自己同位置且被sense到的
        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result.x=it->x;
                result.y=it->y;
                break;
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }
    return result;
}

unsigned int TeamName::ChooseObj(ObjectList& objlist,taskList& tasklist,myTask& para_task)
{
    //unsigned int result=65535;
    C_para_2 result;
    vector<C_para_2>& para_vector=para_task.m_answer_vector;
    //与自己同位置且被sense到的

        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;
            if(objlist.bot.plate==it->x)
            {
                result=*it;
                break;
            }
            if(objlist.bot.hold==it->x)
            {
                result=*it;
                break;
            }
        }

        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
                {
                    result=*it;
                    break;
                }
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result=*it;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;



                if(65535!=firstObj.location)
                {
                    result=*it;
                    break;
                }
            }
        }

        //随便选择一个...
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                result=*it;
                if(result.x==65535)
                    continue;
                break;
            }
        }
        para_task.m_first=result.x;
        para_task.m_second=result.y;

    return result.x;
}

unsigned int TeamName::ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task)
{
    //unsigned int result=65535;
    C_para_2 result;
    vector<C_para_2>& para_vector=para_task.m_answer_vector;
    //与自己同位置且被sense到的

        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;
            if(objlist.bot.plate==it->x)
            {
                result=*it;
                break;
            }
            if(objlist.bot.hold==it->x)
            {
                result=*it;
                break;
            }
        }

        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
                {
                    result=*it;
                    break;
                }
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result=*it;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;



                if(65535!=firstObj.location)
                {
                    result=*it;
                    break;
                }
            }
        }


        para_task.m_first=result.x;
        para_task.m_second=result.y;

    return result.x;
}

unsigned int TeamName::ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<unsigned int> para_vector)
{
    unsigned int result=65535;
    //与自己同位置且被sense到的
        for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,*it);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result=*it;
                break;
            }
        }

        //被sense到的
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result=*it;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result)
        {
            for(vector<unsigned int>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,*it);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result=*it;
                    break;
                }
            }
        }
    return result;
}
//debug new

C_para_2 TeamName::ChooseObj_big(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<C_para_2> para_vector)
{
    C_para_2 result;
        //与自己同位置且被sense到的
        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result.x=it->x;
                result.y=it->y;
                break;
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //随便选择一个...
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                result.x=it->x;
                result.y=it->y;
                if(result.x==65535||result.y==65535)
                    continue;
                break;
            }
        }

    return result;
}

C_para_2 TeamName::ChooseObj_big_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<C_para_2> para_vector)
{
    C_para_2 result;
            //与自己同位置且被sense到的
        for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
        {
            Object& firstObj=getObj_id(objlist,tasklist,it->x);
            if(firstObj==*Object::NULLObj)
                continue;


            if(true==firstObj.sensed&&firstObj.location==objlist.bot.loc)
            {
                result.x=it->x;
                result.y=it->y;
                break;
            }
        }

        //被sense到的
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(true==firstObj.sensed)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }

        //未sense到但已知位置
        if(65535==result.x)
        {
            for(vector<C_para_2>::iterator it=para_vector.begin();it!=para_vector.end();it++)
            {
                Object& firstObj=getObj_id(objlist,tasklist,it->x);
                if(firstObj==*Object::NULLObj)
                    continue;


                if(65535!=firstObj.location)
                {
                    result.x=it->x;
                    result.y=it->y;
                    break;
                }
            }
        }
    return result;
}

int TeamName::ChooseObj_ForAll(ObjectList& objlist,taskList& tasklist)
{
    vector<C_para_2>::iterator toErase;
    bool eraseFlag=false;
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        ChooseObj(objlist,tasklist,*itTask);
    }

    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        if(3==itTask->action||4==itTask->action)
            continue;
        for(vector<myTask>::iterator itTask2=tasklist.task.begin();itTask2!=tasklist.task.end();itTask2++)
        {
            eraseFlag=false;
            if(3==itTask2->action||4==itTask2->action)
                continue;
            if(itTask2==itTask)
            {
                continue;
            }

            if(itTask2->m_first==itTask->m_first)
            {
                if(itTask->m_first_match>itTask2->m_first_match)
                {
                    for(vector<C_para_2>::iterator it=itTask2->m_answer_vector.begin();it!=itTask2->m_answer_vector.end();it++)
                    {
                        if(it->x==itTask->m_first)
                        {
                            toErase=it;
                            eraseFlag=true;
                            break;
                        }
                    }
                    if(true==eraseFlag)
                    {
                        itTask2->m_answer_vector.erase(toErase);
                        ChooseObj_ForAll(objlist,tasklist);
                    }
                }
                else
                {
                    for(vector<C_para_2>::iterator it=itTask->m_answer_vector.begin();it!=itTask->m_answer_vector.end();it++)
                    {
                        if(it->x==itTask2->m_first)
                        {
                            toErase=it;
                            eraseFlag=true;
                            break;
                        }
                    }
                    if(true==eraseFlag)
                    {
                        itTask->m_answer_vector.erase(toErase);
                        ChooseObj_ForAll(objlist,tasklist);
                    }
                }

            }

        }
    }


    return 0;
}




int TeamName::supplyTaskList(ObjectList& objlist,taskList& tasklist)
{
    int mode=0;
    int humanId;
    unsigned int match_num=0;
    bool continueFlag=false;
    C_para_2 toUpload;
    humanId=getObjId_name(objlist,tasklist,"human");
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        continueFlag=false;
        if(true==itTask->is_done)
        {
            continue;
        }
        /*
        if(true==itTask->is_doing)
        {
            continue;
        }
        */
        switch(itTask->action)
        {
            case 1:
                //give(human,obj1)
                if(itTask->firstVar!="human")
                {
                    itTask->secondVar=itTask->firstVar;
                }
                else
                {
                    itTask->firstVar=itTask->secondVar;
                }
                mode=1;
                break;
            case 2:
                //puton(small,big)
                mode=2;
                break;
            case 3:
                //goto(obj)
                mode=1;
                break;
            case 4:
                //putdown(obj)
                mode=1;
                break;
            case 5:
                //pickup(obj)
                mode=1;
                break;
            case 6:
                //open(obj)
                mode=1;
                break;
            case 7:
                //putin(id,continer)
                mode=2;
                break;
            case 8:
                //close(obj)
                mode=1;
                break;
            case 9:
                //takeout(id,continer)
                mode=2;
                break;
            default:
                if(debug)
                    cout<<"task error"<<endl;
                break;
        }


        if(1==mode)
        {
            Object& firstObj=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->firstVar);
            if(firstObj!=*Object::NULLObj)
            {
                for(vector<unsigned int>::iterator itFirst=firstObj.answer_vectorId.begin();itFirst!=firstObj.answer_vectorId.end();itFirst++)
                {
                    continueFlag=false;
                    Object& target=getObj_id(objlist,tasklist,*itFirst);
                    if(target==*Object::NULLObj)
                    {
                            continue;
                    }


                    switch(itTask->action)
                    {
                        case 1:
                            //give(human,obj1)
                            if(target.size==2)
                                continueFlag=true;
                            if(2==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 2:
                            //puton(small,big)
                            if(target.size==2)
                                continueFlag=true;
                            if(2==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 3:
                            //goto(obj)
                            if(1==target.give_up)
                                continueFlag=true;
                            break;
                        case 4:
                            //putdown(obj)
                            if(target.size==2)
                                continueFlag=true;
                            if(1==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 5:
                            //pickup(obj)
                            if(target.size==2)
                                continueFlag=true;
                            if(2==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 6:
                            //open(obj)
                            if(1==target.keep_door)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 7:
                            //putin(id,continer)
                            if(target.size==2)
                                continueFlag;
                            if(2==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 8:
                            //close(obj)
                            if(1==target.keep_door)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        case 9:
                            //takeout(id,continer)
                            if(target.size==2)
                                continueFlag;
                            if(2==target.hold_locked)
                                continueFlag=true;
                            if(target.is_locked==1)
                                continueFlag=true;
                            break;
                        default:
                            if(debug)
                                cout<<"task error"<<endl;
                            break;
                    }

                    for(vector<struct no_task>::iterator itNoTask=target.no_action.begin();itNoTask!=target.no_action.end();itNoTask++)
                    {
                        if(itNoTask->action==3)
                        {
                            continueFlag=true;
                        }
                        if(itNoTask->action==itTask->action)
                        {
                            continueFlag=true;
                        }
                    }

                    if(continueFlag==true)
                    {
                        continue;
                    }
                    toUpload.x=*itFirst;
                    toUpload.y=65535;
                    if(1==itTask->action)
                    {
                        toUpload.y=humanId;
                    }
                    itTask->m_answer_vector.push_back(toUpload);
                }
            }
        }

        if(2==mode)
        {

            Object& targetObj=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->firstVar);
            Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->secondVar);
            if(targetObj!=*Object::NULLObj)
            {

                for(vector<unsigned int>::iterator itId=targetObj.answer_vectorId.begin();itId!=targetObj.answer_vectorId.end();itId++)
                {

                    continueFlag=false;
                    Object& target=getObj_id(objlist,tasklist,*itId);

                    if(target==*Object::NULLObj)
                    {
                        continue;
                    }

                    if(true==target.is_locked)
                    {
                        continue;
                    }

                    for(vector<unsigned int>::iterator itcId=targetObj_c.answer_vectorId.begin();itcId!=targetObj_c.answer_vectorId.end();itcId++)
                    {
                        //cout<<*itId<<"  "<<*itcId<<endl;
                        continueFlag=false;
                        Object& targetBig=getObj_id(objlist,tasklist,*itcId);
                        if(targetBig==*Object::NULLObj)
                        {
                            continue;
                        }




                        switch(itTask->action)
                        {
                            case 1:
                                //give(human,obj1)
                                if(target.size==2)
                                    continueFlag=true;
                                if(2==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 2:
                                //puton(small,big)
                                if(target.size==2)
                                    continueFlag=true;
                                if(2==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 3:
                                //goto(obj)
                                if(1==target.give_up)
                                    continueFlag=true;
                                break;
                            case 4:
                                //putdown(obj)
                                if(target.size==2)
                                    continueFlag=true;
                                if(1==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 5:
                                //pickup(obj)
                                if(target.size==2)
                                    continueFlag=true;
                                if(2==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 6:
                                //open(obj)
                                if(1==target.keep_door)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 7:
                                //putin(id,continer)
                                if(target.size==2)
                                    continueFlag=true;
                                if(targetBig.size==1)
                                    continueFlag=true;
                                if(2==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 8:
                                //close(obj)
                                if(1==target.keep_door)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            case 9:
                                //takeout(id,continer)
                                if(target.size==2)
                                    continueFlag=true;
                                if(targetBig.size==1)
                                    continueFlag=true;
                                if(2==target.hold_locked)
                                    continueFlag=true;
                                if(target.is_locked==1)
                                    continueFlag=true;
                                break;
                            default:
                                if(debug)
                                    cout<<"task error"<<endl;
                                break;
                        }
                        if(itTask->action==2||itTask->action==7||itTask->action==9)
                        {

                            for(vector<struct no_task>::iterator itNoTaskBig=targetBig.no_action.begin();itNoTaskBig!=targetBig.no_action.end();itNoTaskBig++)
                            {
                                if(itNoTaskBig->action==3)
                                {

                                    continueFlag=true;
                                }
                            }

                        }
                        for(vector<struct no_task>::iterator itNoTask=target.no_action.begin();itNoTask!=target.no_action.end();itNoTask++)
                        {
                            if(itTask->action==2||itTask->action==7||itTask->action==9)
                            {
                                if(itNoTask->action==5)
                                {
                                    continueFlag=true;
                                }
                            }
                            if(itNoTask->action==3)
                            {
                                continueFlag=true;
                            }

                            if(itNoTask->action==itTask->action&&itNoTask->actionId==*itcId)
                            {
                                continueFlag=true;
                            }
                        }


                        if(true==continueFlag)
                            continue;
                        toUpload.x=*itId;
                        toUpload.y=*itcId;
                        itTask->m_answer_vector.push_back(toUpload);


                        //debug new

                    }
                }
            }
        }
        Object& targetObj=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->firstVar);
        Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->secondVar);
        if(targetObj!=*Object::NULLObj)
        {
            match_num=0;
            if(targetObj.name!="")
                match_num++;
            if(targetObj.color!=65535)
                match_num++;
            itTask->m_first_match=match_num;
        }

        if(targetObj_c!=*Object::NULLObj)
        {
            match_num=0;
            if(targetObj.name!="")
                match_num++;
            if(targetObj.color!=65535)
                match_num++;
            itTask->m_second_match=match_num;
        }

    }
    return 0;
}


int TeamName::InsertTask(ObjectList& objlist,taskList& tasklist)
{
    bool continueFlag=false;
    bool insertSuccess=false;
    unsigned int xId=65535;
    unsigned int yId=65535;
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        continueFlag=false;
        xId=65535;
        yId=65535;
        if(itTask->is_done==true)
        {
            continueFlag=true;
        }
        if(itTask->is_doing==true)
        {
            continueFlag=true;
        }

        if(3==itTask->action)//goto
            continueFlag=true;
        if(4==itTask->action)//putdown
            continueFlag=true;

        if(5==itTask->action)//pickup
        {
            continueFlag=true;
        }
        if(8==itTask->action)//close
        {
            continueFlag=true;
        }

        if(true==continueFlag)
            continue;

        for(vector<C_para_2>::iterator itX=itTask->m_answer_vector.begin();itX!=itTask->m_answer_vector.end();itX++)
        {
            for(vector<unsigned int>::iterator it=objlist.bot.here.begin();it!=objlist.bot.here.end();it++)
            {
                if(itX->x==*it)
                {
                    xId=itX->x;
                    yId=itX->y;

                    break;
                }
            }
            if(xId!=65535)
            {
                break;
            }
            else
            {
                itTask->m_first=xId;
                itTask->m_second=yId;
            }
        }

        if(xId==65535)
            continueFlag=true;


        if(true==continueFlag)
            continue;

        letsGo(objlist,tasklist,*itTask);
        insertSuccess=true;
        itTask->is_done=true;
        break;
    }



    if(false==insertSuccess)
    {
        for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
        {
            continueFlag=false;
            xId=65535;
            yId=65535;
            if(itTask->is_done==true)
            {
                continueFlag=true;
            }
            if(itTask->is_doing==true)
            {
                continueFlag=true;
            }

            if(3==itTask->action)//goto
                continueFlag=true;
            if(4==itTask->action)//putdown
                continueFlag=true;

            if(5==itTask->action)//pickup
            {
                continueFlag=true;
            }
            if(8==itTask->action)//close
            {
                continueFlag=true;
            }

            if(true==continueFlag)
                continue;

            letsGo(objlist,tasklist,*itTask);
            itTask->is_done=true;
            break;
        }
    }


    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int TeamName::cGoto(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    //working last
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned int targetNum_Sense=65535;
    vector<unsigned int> num_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=3;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);



    if(targetObj!=*Object::NULLObj)
    {


        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        if(targetNum!=65535)
        {
            offset=cGoto(objlist,tasklist,targetNum,false);
        }
        else
        {
            return -3;
        }

        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cGoto(objlist,tasklist,mytask);
            return offset;
        }

        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            if(targetNum!=65535)
                offset=cGoto(objlist,tasklist,targetNum,false);
            else
                return -3;
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cGoto(objlist,tasklist,mytask);
                return offset;
            }
        }
        done_flag=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cGoto(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag)//debug
{
    const unsigned int actionNum=3;
    int offset=0;
    unsigned int actionId=3;

    unsigned int targetLoc;
    unsigned int temp;
    targetLoc=getObjLoc_id(objlist,tasklist,id);//获取要去的位置

    if(targetLoc<0)//如果没有找到位置执行ask
    {
        targetLoc=askLoc_id(objlist,tasklist,id);
    }

    if(objlist.bot.loc!=targetLoc)//如果自己不在目标位置则 移动到 目标位置
    {
        offset=resHandler_nInfo(objlist,tasklist,1,targetLoc,0,check_flag);//eMove(targetLoc); 移动到目标位置
    }
    return offset;
}

int TeamName::cOpen(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;
    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=6;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);

    if(targetObj!=*Object::NULLObj)
    {


        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        Object& objX=getObj_id(objlist,tasklist,targetNum);
        if(objX!=*Object::NULLObj)
        {
            if(objX.is_open==1)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }

        if(targetNum!=65535)
            offset=cOpen(objlist,tasklist,targetNum,false);
        else
            return -3;
        if(offset==-1)
        {
            mytask.is_doing=false;
            return -1;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cOpen(objlist,tasklist,targetNum,false);
        }
        done_flag=true;
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }


    mytask.is_doing=false;
    return 0;
}

int TeamName::cOpen(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag)
{
    const unsigned int actionNum=6;
    unsigned int offset=0;
    unsigned int tempHold;
    if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
    {

        if(1!=(getObj_id(objlist,tasklist,objlist.bot.hold).hold_locked))
        {
            if(objlist.bot.plate==0)
            {
                offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                tempHold=objlist.bot.hold;
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
                if(offset==-1)
                    return -1;
                offset=resHandler_nInfo(objlist,tasklist,5,objlist.bot.plate,0,check_flag);//eFromPlate(plate);
                if(offset==-1)
                    return -1;
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
                if(offset==-1)
                    return -1;
                offset=resHandler_nInfo(objlist,tasklist,2,tempHold,0,check_flag);//ePickUp(tempHold);
                if(offset==-1)
                    return -1;
                offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
        }
    }

    if(getObj_id(objlist,tasklist,id).is_open!=1)
    {
        offset=cGoto(objlist,tasklist,id,check_flag);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;
        offset=resHandler_nInfo(objlist,tasklist,6,id,0,check_flag);//eOpen(id);
        if(offset==-1)
            return -1;
    }
    return offset;
}

int TeamName::cClose(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;
    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=8;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_Sense(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        Object& objX=getObj_id(objlist,tasklist,targetNum);
        if(objX!=*Object::NULLObj)
        {
            if(objX.is_open==2)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }
        if(targetNum!=65535)
            offset=cClose(objlist,tasklist,targetNum,false);
        else
            return -3;
        if(offset==-1)
        {
            mytask.is_doing=false;
            return -1;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cClose(objlist,tasklist,targetNum,false);
        }
        done_flag=true;
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }
    mytask.is_doing=false;
    return 0;
}

int TeamName::cClose(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag)
{
    const unsigned int actionNum=8;
    unsigned int offset=0;
    unsigned int tempHold;
    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);
    Object& objPlate=getObj_id(objlist,tasklist,objlist.bot.plate);
    if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
    {
        if(can_plate_id(objlist,tasklist,objlist.bot.hold)&&(objHold.hold_flag==1||objHold.hold_locked==1)&&objlist.bot.plate==0)
        {
            offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
            if(offset==-1)
                return -1;
        }
        else if((objHold.hold_flag==1||objHold.hold_locked==1)&&objPlate.hold_locked!=2)
        {
            tempHold=objlist.bot.hold;
            offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                    return -1;
            offset=resHandler_nInfo(objlist,tasklist,5,objlist.bot.plate,0,check_flag);//eFromPlate(plate);
            if(offset==-1)
                    return -1;
            offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                    return -1;
            offset=resHandler_nInfo(objlist,tasklist,2,tempHold,0,check_flag);//ePickUp(tempHold);
            if(offset==-1)
                    return -1;
            offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
            if(offset==-1)
                return -1;
        }
        else
        {
            offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
    }
    //debug

    if(getObj_id(objlist,tasklist,id).is_open!=2)
    {
        offset=cGoto(objlist,tasklist,id,check_flag);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;
        offset=resHandler_nInfo(objlist,tasklist,7,id,0,check_flag);//eClose(id);
        if(offset==-1)
            return -1;
    }
    return offset;
}

int TeamName::cTakeOut(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=9;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;

        Object& objX=getObj_id(objlist,tasklist,targetNum.x);
        if(objX!=*Object::NULLObj)
        {
            if(objX.is_inside!=targetNum.y&&objX.is_inside!=65535)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }

        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cTakeOut(objlist,tasklist,targetNum.x,targetNum.y,false);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cTakeOut(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cTakeOut(objlist,tasklist,targetNum.x,targetNum.y,false);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cTakeOut(objlist,tasklist,mytask);
                return offset;
            }
        }

        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}


int TeamName::cTakeOut(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId,int check_flag)
{
    const unsigned int actionNum=9;
    int offset=0;
    unsigned int targetLoc;

    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);
    if(objHold!=*Object::NULLObj)
    {
        for(vector<struct no_task>::iterator itNoTask=objHold.no_action.begin();itNoTask!=objHold.no_action.end();itNoTask++)
        {
            if(itNoTask->action==4)
            {
                objHold.hold_locked=1;
            }
        }
    }
    Object& container=getObj_id(objlist,tasklist,continerId);
    if(container!=*Object::NULLObj)
    {
        if(container.keep_door==1&&container.is_open==2)
        {
            return -1;
        }
        offset=cGoto(objlist,tasklist,continerId,check_flag);
        if(offset==-1)
            return -1;
        if(-10==offset)
            return -10;
        if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
        {
            if(0==objlist.bot.plate&&(objHold.hold_flag==1||objHold.hold_locked==1))
            {
                offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
        }
        if(container.is_open!=1)
        {
            offset=cOpen(objlist,tasklist,continerId,check_flag);
            if(offset==-1)
                return -1;
        }
        if(id==eSense(objlist,tasklist,id))
        {
            offset=resHandler_nInfo(objlist,tasklist,9,id,continerId,check_flag);//eTakeOut(id,containerId);
            if(offset==-1)
                offset=resHandler_nInfo(objlist,tasklist,2,id,0,check_flag);//ePickUp(id,containerId);
            if(offset==-1)
                return -1;
        }
    }

    //continerId=inContiner_id(objlist,tasklist,id);
    return offset;
}


int TeamName::cPickUp(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator  toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=5;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;


        if(targetNum!=65535)
            offset=cPickUp(objlist,tasklist,targetNum,false);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPickUp(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cPickUp(objlist,tasklist,targetNum,false);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPickUp(objlist,tasklist,mytask);
                return offset;
            }
        }
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPickUp(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag)
{
    const unsigned int actionNum=5;
    unsigned int offset=0;
    unsigned int targetLoc;
    unsigned int temp;
    unsigned int containerId=0;


    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);

    if(objlist.bot.hold!=id&&objlist.bot.plate!=id)
    {
        if(objlist.bot.hold!=0)
        {
            if(0==objlist.bot.plate&&(objHold.hold_flag==1||objHold.hold_locked==1)&&objHold.need_plate!=2)
            {
                offset=resHandler_nInfo(objlist,tasklist,4,objlist.bot.hold,0,check_flag);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else if(0==objlist.bot.plate)
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
        }

        containerId=inContiner_id(objlist,tasklist,id,0);
        if(containerId!=0)
        {
            Object& container=getObj_id(objlist,tasklist,containerId);
            if(container.keep_door==1)
            {
                return -1;
            }
            offset=cGoto(objlist,tasklist,containerId,check_flag);
            if(offset==-1)
                return -1;
            if(-10==offset)
                return -10;
            if(container!=*Object::NULLObj)
            {
                if(container.is_open!=1)
                {
                    offset=resHandler_nInfo(objlist,tasklist,6,containerId,0,check_flag);//eOpen(containerId);
                    if(offset==-1)
                        return -1;
                }
            }
            else
            {

            }
            if(id==eSense(objlist,tasklist,id))
            {
                offset=resHandler_nInfo(objlist,tasklist,9,id,containerId,check_flag);//eTakeOut(id,containerId);

                if(offset==-1)
                    offset=resHandler_nInfo(objlist,tasklist,2,id,0,check_flag);
                if(offset==-1)
                    return -1;
            }
            else
            {
                Object& id_Obj=getObj_id(objlist,tasklist,id);
                if(id_Obj!=*Object::NULLObj)
                {
                    id_Obj.is_inside=65535;
                }
                if(true==NEWPLAN)
                {
                    return -10;
                }
                askLoc_id(objlist,tasklist,id);
                offset=cPickUp(objlist,tasklist,id,check_flag);
                if(offset==-1)
                    return -1;
                if(-10==offset)
                    return -10;
            }
        }
        else
        {
            offset=cGoto(objlist,tasklist,id,check_flag);
            if(offset==-1)
                return -1;
            if(-10==offset)
                return -10;
            if(id==eSense(objlist,tasklist,id))
            {
                if(containerId=inContiner_id(objlist,tasklist,id,0))
                {
                    Object& container=getObj_id(objlist,tasklist,containerId);
                    if(container!=*Object::NULLObj)
                    {
                        if(container.is_open!=1)
                        {
                            offset=resHandler_nInfo(objlist,tasklist,6,containerId,0,check_flag);//eOpen(containerId);
                            if(offset==-1)
                                return -1;
                        }
                        offset=resHandler_nInfo(objlist,tasklist,9,id,containerId,check_flag);//eTakeOut(id,containerId);
                        if(offset==-1)
                            return -1;
                    }
                }
                else
                {
                    offset=resHandler_nInfo(objlist,tasklist,2,id,0,check_flag);//ePickUp(id);
                    if(offset==-1)
                        return -1;
                    if(offset==0)//offset=0;
                    {
                        eSense(objlist,tasklist,id);
                        for(vector<unsigned int>::iterator it=objlist.bot.here.begin();it!=objlist.bot.here.end();it++)
                        {
                            Object& objIt=getObj_id(objlist,tasklist,*it);
                            if(objIt!=*Object::NULLObj)
                            {
                                //debug takeout
                                if(objIt.type=="container")
                                {
                                    if(objIt.is_open!=1)
                                    {
                                        offset=resHandler_nInfo(objlist,tasklist,6,objIt.id,0,check_flag);//eOpen(objIt);
                                        if(offset==-1)
                                            return -1;
                                    }
                                    offset=resHandler_nInfo(objlist,tasklist,9,id,*it,check_flag);//eTakeOut(id,objIt);
                                    if(offset==-1)
                                        return -1;
                                }
                            }
                        }
                    }
                }
            }
            else
            {

                Object& target=getObj_id(objlist,tasklist,id);
                if(target!=*Object::NULLObj)
                {
                    target.location=65535;
                }
                if(true==NEWPLAN)
                {
                    return -10;
                }
                askLoc_id(objlist,tasklist,id);
                offset=cPickUp(objlist,tasklist,id,check_flag);
                if(offset==-1)
                    return -1;
                if(-10==offset)
                    return -10;
            }
        }
    }
    return offset;
}

int TeamName::cPutDown(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=4;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);

    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;

        if(targetNum!=65535)
            offset=cPutDown(objlist,tasklist,targetNum,false);
        else
            return -3;


        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutDown(objlist,tasklist,mytask);
            return offset;
        }

        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cPutDown(objlist,tasklist,targetNum,false);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutDown(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum).hold_locked=2;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}
int TeamName::cPutDown(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag)
{
    const unsigned int actionNum=3;
    int offset=0;
    unsigned int temp;



    if(objlist.bot.hold==id)//东西在手中时   直接放下
    {

        offset=resHandler_nInfo(objlist,tasklist,3,id,0,check_flag);//ePutDown(id);
        if(offset==-1)
            return -1;
    }
    else if(objlist.bot.plate==id)//东西在盘子中时
    {
        if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
        {
            temp=objlist.bot.hold;
            offset=resHandler_nInfo(objlist,tasklist,3,temp,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                return -1;
            offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(plate);
            if(offset==-1)
                return -1;
            offset=resHandler_nInfo(objlist,tasklist,3,id,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
        else
        {
            offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(plate);
            if(offset==-1)
                return -1;
            offset=resHandler_nInfo(objlist,tasklist,3,id,0,check_flag);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
    }
    return offset;
}

int TeamName::cPutOn(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{

    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=2;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;

        Object& objX=getObj_id(objlist,tasklist,targetNum.x);
        Object& objY=getObj_id(objlist,tasklist,targetNum.y);

        if(objX!=*Object::NULLObj&&objY!=*Object::NULLObj)
        {
            if(objX.location==objY.location&&objX.location!=65535)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }


        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cPutOn(objlist,tasklist,targetNum.x,targetNum.y,true);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutOn(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cPutOn(objlist,tasklist,targetNum.x,targetNum.y,true);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutOn(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPutOn(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId,int check_flag)
{
    const unsigned int actionNum=2;
    int offset=0;
    unsigned int continerId;

    offset=cPickUp(objlist,tasklist,id,check_flag);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;

    offset=cGoto(objlist,tasklist,bigId,check_flag);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;

    offset=cPutDown(objlist,tasklist,id,check_flag);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;
    //cout<<"xx:"<<offset<<endl;
    return offset;
}

int TeamName::cPutIn(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=7;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;

        Object& objX=getObj_id(objlist,tasklist,targetNum.x);
        if(objX!=*Object::NULLObj)
        {
            if(objX.is_inside==targetNum.y&&objX.is_inside!=65535)
            {
                mytask.is_ignored=true;
                return 0;
            }
        }


        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cPutIn(objlist,tasklist,targetNum.x,targetNum.y,false);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector.end())
            {
                mytask.m_answer_vector.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutIn(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cPutIn(objlist,tasklist,targetNum.x,targetNum.y,false);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector.begin();it!=mytask.m_answer_vector.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector.end())
                {
                    mytask.m_answer_vector.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutIn(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPutIn(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId,int check_flag)
{
    const unsigned int actionNum=7;
    int offset=0;
    unsigned int inContinerId;
    inContinerId=inContiner_id(objlist,tasklist,id,0);
    Object& obj=getObj_id(objlist,tasklist,id);

    if(inContinerId!=continerId)
    {
        offset=cPickUp(objlist,tasklist,id,check_flag);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;

        if(objlist.bot.plate==id)
        {
            if(objlist.bot.hold==0)
            {
                offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(id)
            }
            else
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold)
                offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(id)
            }
        }

        offset=cGoto(objlist,tasklist,continerId,check_flag);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;

        if(objlist.bot.plate==id)
        {
            if(objlist.bot.hold==0)
            {
                offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(id)
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(hold)
                offset=resHandler_nInfo(objlist,tasklist,5,id,0,check_flag);//eFromPlate(id)
                if(offset==-1)
                    return -1;
            }
        }


        if(1!=getObj_id(objlist,tasklist,continerId).is_open)
        {
            if(objlist.bot.hold==id)
            {
                offset=resHandler_nInfo(objlist,tasklist,3,id,0,check_flag);//ePutDown(id);
                if(offset==-1)
                    return -1;
                Object& contain=getObj_id(objlist,tasklist,continerId);
                if(contain!=*Object::NULLObj)
                {
                    if(contain.is_open!=1)
                    {
                        offset=resHandler_nInfo(objlist,tasklist,6,continerId,0,check_flag);//eOpen(contin);
                        if(offset==-1)
                            return -1;
                    }
                }
                offset=resHandler_nInfo(objlist,tasklist,2,id,0,check_flag);//ePickUp(id);
                if(offset==-1)
                    return -1;
            }
            else if(objlist.bot.hold!=0)
            {
                offset=resHandler_nInfo(objlist,tasklist,3,objlist.bot.hold,0,check_flag);//ePutDown(id);
                    if(offset==-1)
                        return -1;
                Object& contain=getObj_id(objlist,tasklist,continerId);
                if(contain!=*Object::NULLObj)
                {
                    if(contain.is_open!=1)
                    {
                        offset=resHandler_nInfo(objlist,tasklist,6,continerId,0,check_flag);//eOpen(contin);
                        if(offset==-1)
                            return -1;
                    }
                }
                offset=resHandler_nInfo(objlist,tasklist,5,objlist.bot.plate,0,check_flag);//eFromPlate(plate);
                    if(offset==-1)
                        return -1;

            }
        }
        offset=resHandler_nInfo(objlist,tasklist,8,id,continerId,check_flag);//ePutIn(id,continerId);
        if(offset==-1)
            return -1;
    }

    return offset;
}
/*action_no_res*/
int TeamName::cGive_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    unsigned int humanId=65535;
    humanId=getObjId_name(objlist,tasklist,"human");
    string objVar;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=2;

    if(mytask.firstVar!="human")
    {
        objVar=mytask.firstVar;
    }
    else
    {
        objVar=mytask.secondVar;
    }
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,objVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector_backup);


        if(targetNum.x!=65535&&targetNum.y!=65535)
        {
            offset=cPutOn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
        }
        else
        {
            return -3;
        }

        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum.x)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cGive_no_res(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector_backup);
            if(targetNum_Sense.x!=65535)
                targetNum=targetNum_Sense;
            else
            {

            }
            if(targetNum.x!=65535&&targetNum.y!=65535)
            {
                offset=cPutOn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
            }
            else
            {
                return -3;
            }
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum.x)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cGive(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;

    return offset;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int TeamName::cGoto_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    //working last
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned int targetNum_Sense=65535;
    vector<unsigned int> num_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=3;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);



    if(targetObj!=*Object::NULLObj)
    {


        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        if(targetNum!=65535)
        {
            offset=cGoto_no_res(objlist,tasklist,targetNum);
        }
        else
        {
            return -3;
        }

        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cGoto_no_res(objlist,tasklist,mytask);
            return offset;
        }

        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            if(targetNum!=65535)
                offset=cGoto_no_res(objlist,tasklist,targetNum);
            else
                return -3;
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cGoto_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }
        done_flag=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cGoto_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id)//debug
{
    const unsigned int actionNum=3;
    int offset=0;
    unsigned int actionId=3;

    unsigned int targetLoc;
    unsigned int temp;
    targetLoc=getObjLoc_id(objlist,tasklist,id);//获取要去的位置

    if(targetLoc<0)//如果没有找到位置执行ask
    {
        targetLoc=askLoc_id(objlist,tasklist,id);
    }

    if(objlist.bot.loc!=targetLoc)//如果自己不在目标位置则 移动到 目标位置
    {
        offset=Do_no_res(objlist,tasklist,1,targetLoc,0);//eMove(targetLoc); 移动到目标位置
    }
    return offset;
}

int TeamName::cOpen_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;
    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=6;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);

    if(targetObj!=*Object::NULLObj)
    {


        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        if(targetNum!=65535)
            offset=cOpen_no_res(objlist,tasklist,targetNum);
        else
            return -3;
        if(offset==-1)
        {
            mytask.is_doing=false;
            return -1;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cOpen_no_res(objlist,tasklist,targetNum);
        }
        done_flag=true;
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }


    mytask.is_doing=false;
    return 0;
}

int TeamName::cOpen_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    const unsigned int actionNum=6;
    unsigned int offset=0;
    unsigned int tempHold;
    if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
    {
        if(1==getObj_id(objlist,tasklist,objlist.bot.hold).hold_locked)
        {
            if(objlist.bot.plate==0)
            {
                offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                tempHold=objlist.bot.hold;
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
                if(offset==-1)
                    return -1;
                offset=Do_no_res(objlist,tasklist,5,objlist.bot.plate,0);//eFromPlate(plate);
                if(offset==-1)
                    return -1;
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
                if(offset==-1)
                    return -1;
                offset=Do_no_res(objlist,tasklist,2,tempHold,0);//ePickUp(tempHold);
                if(offset==-1)
                    return -1;
                offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
        }
    }

    if(getObj_id(objlist,tasklist,id).is_open!=1)
    {
        offset=cGoto_no_res(objlist,tasklist,id);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;
        offset=Do_no_res(objlist,tasklist,6,id,0);//eOpen(id);
        if(offset==-1)
            return -1;
    }
    return offset;
}

int TeamName::cClose_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;
    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=8;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_Sense(objlist,tasklist,mytask);
        mytask.m_first=targetNum;
        if(targetNum!=65535)
            offset=cClose_no_res(objlist,tasklist,targetNum);
        else
            return -3;
        if(offset==-1)
        {
            mytask.is_doing=false;
            return -1;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cClose_no_res(objlist,tasklist,targetNum);
        }
        done_flag=true;
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }
    mytask.is_doing=false;
    return 0;
}

int TeamName::cClose_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    const unsigned int actionNum=8;
    unsigned int offset=0;
    unsigned int tempHold;
    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);
    Object& objPlate=getObj_id(objlist,tasklist,objlist.bot.plate);
    if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
    {
        if(can_plate_id(objlist,tasklist,objlist.bot.hold)&&(objHold.hold_flag==1||objHold.hold_locked==1)&&objlist.bot.plate==0)
        {
            offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
            if(offset==-1)
                return -1;
        }
        else if((objHold.hold_flag==1||objHold.hold_locked==1)&&objPlate.hold_locked!=2)//else if((objHold.hold_flag==1||objHold.hold_locked==1)&&objPlate.hold_locked!=1)
        {
            tempHold=objlist.bot.hold;
            offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
            if(offset==-1)
                    return -1;
            offset=Do_no_res(objlist,tasklist,5,objlist.bot.plate,0);//eFromPlate(plate);
            if(offset==-1)
                    return -1;
            offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
            if(offset==-1)
                    return -1;
            offset=Do_no_res(objlist,tasklist,2,tempHold,0);//ePickUp(tempHold);
            if(offset==-1)
                    return -1;
            offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
            if(offset==-1)
                return -1;
        }
        else
        {
            offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
    }
    //debug

    if(getObj_id(objlist,tasklist,id).is_open!=2)
    {
        offset=cGoto_no_res(objlist,tasklist,id);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;
        offset=Do_no_res(objlist,tasklist,7,id,0);//eClose(id);
        if(offset==-1)
            return -1;
    }
    return offset;
}

int TeamName::cTakeOut_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=9;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector_backup);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;
        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cTakeOut_no_res(objlist,tasklist,targetNum.x,targetNum.y);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cTakeOut_no_res(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector_backup);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cTakeOut_no_res(objlist,tasklist,targetNum.x,targetNum.y);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cTakeOut_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }

        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}


int TeamName::cTakeOut_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId)
{
    const unsigned int actionNum=9;
    int offset=0;
    unsigned int targetLoc;

    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);
    if(objHold!=*Object::NULLObj)
    {
        for(vector<struct no_task>::iterator itNoTask=objHold.no_action.begin();itNoTask!=objHold.no_action.end();itNoTask++)
        {
            if(itNoTask->action==4)
            {
                objHold.hold_locked=1;
            }
        }
    }
    Object& container=getObj_id(objlist,tasklist,continerId);
    if(container!=*Object::NULLObj)
    {
        if(container.is_open==2)
        {
            return -1;
        }
        offset=cGoto_no_res(objlist,tasklist,continerId);
        if(offset==-1)
            return -1;
        if(-10==offset)
            return -10;
        if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
        {
            if(0==objlist.bot.plate&&(objHold.hold_flag==1||objHold.hold_locked==1))
            {
                offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
        }
        if(container.is_open!=1)
        {
            offset=cOpen_no_res(objlist,tasklist,continerId);
            if(offset==-1)
                return -1;
        }
        if(id==eSense(objlist,tasklist,id))
        {
            offset=Do_no_res(objlist,tasklist,9,id,continerId);//eTakeOut(id,containerId);
            if(offset==-1)
                offset=Do_no_res(objlist,tasklist,2,id,0);//ePickUp(id,containerId);
            if(offset==-1)
                return -1;
        }
    }

    //continerId=inContiner_id(objlist,tasklist,id);
    return offset;
}


int TeamName::cPickUp_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator  toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=5;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;


        if(targetNum!=65535)
            offset=cPickUp_no_res(objlist,tasklist,targetNum);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPickUp_no_res(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cPickUp_no_res(objlist,tasklist,targetNum);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPickUp_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }
        mytask.is_done=true;
        getObj_id(objlist,tasklist,targetNum).is_locked=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPickUp_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    const unsigned int actionNum=5;
    unsigned int offset=0;
    unsigned int targetLoc;
    unsigned int temp;
    unsigned int containerId=0;


    Object& objHold=getObj_id(objlist,tasklist,objlist.bot.hold);

    if(objlist.bot.hold!=id&&objlist.bot.plate!=id)
    {
        if(objlist.bot.hold!=0)
        {
            if(0==objlist.bot.plate&&(objHold.hold_flag==1||objHold.hold_locked==1)&&objHold.need_plate!=2)
            {
                offset=Do_no_res(objlist,tasklist,4,objlist.bot.hold,0);//eToPlate(hold);
                if(offset==-1)
                    return -1;
            }
            else if(0==objlist.bot.plate)
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold);
                if(offset==-1)
                    return -1;
            }
        }

        containerId=inContiner_id(objlist,tasklist,id,0);
        if(containerId!=0)
        {
            Object& container=getObj_id(objlist,tasklist,containerId);
            offset=cGoto_no_res(objlist,tasklist,containerId);
            if(offset==-1)
                return -1;
            if(-10==offset)
                return -10;
            if(container!=*Object::NULLObj)
            {
                if(container.is_open!=1)
                {
                    offset=Do_no_res(objlist,tasklist,6,containerId,0);//eOpen(containerId);
                    if(offset==-1)
                        return -1;
                }
            }
            else
            {

            }
            if(id==eSense(objlist,tasklist,id))
            {
                offset=Do_no_res(objlist,tasklist,9,id,containerId);//eTakeOut(id,containerId);

                if(offset==-1)
                    offset=Do_no_res(objlist,tasklist,2,id,0);
                if(offset==-1)
                    return -1;
            }
            else
            {
                Object& id_Obj=getObj_id(objlist,tasklist,id);
                if(id_Obj!=*Object::NULLObj)
                {
                    id_Obj.is_inside=65535;
                }
                if(true==NEWPLAN)
                {
                    return -10;
                }
                askLoc_id(objlist,tasklist,id);
                offset=cPickUp_no_res(objlist,tasklist,id);
                if(offset==-1)
                    return -1;
                if(-10==offset)
                    return -10;
            }
        }
        else
        {
            offset=cGoto_no_res(objlist,tasklist,id);
            if(offset==-1)
                return -1;
            if(-10==offset)
                return -10;
            if(id==eSense(objlist,tasklist,id))
            {
                if(containerId=inContiner_id(objlist,tasklist,id,0))
                {
                    Object& container=getObj_id(objlist,tasklist,containerId);
                    if(container!=*Object::NULLObj)
                    {
                        if(container.is_open!=1)
                        {
                            offset=Do_no_res(objlist,tasklist,6,containerId,0);//eOpen(containerId);
                            if(offset==-1)
                                return -1;
                        }
                        offset=Do_no_res(objlist,tasklist,9,id,containerId);//eTakeOut(id,containerId);
                        if(offset==-1)
                            return -1;
                    }
                }
                else
                {
                    offset=Do_no_res(objlist,tasklist,2,id,0);//ePickUp(id);
                    if(offset==-1)
                        return -1;
                    if(offset==0)//offset=0;
                    {
                        eSense(objlist,tasklist,id);
                        for(vector<unsigned int>::iterator it=objlist.bot.here.begin();it!=objlist.bot.here.end();it++)
                        {
                            Object& objIt=getObj_id(objlist,tasklist,*it);
                            if(objIt!=*Object::NULLObj)
                            {
                                //debug takeout
                                if(objIt.type=="container")
                                {
                                    if(objIt.is_open!=1)
                                    {
                                        offset=Do_no_res(objlist,tasklist,6,objIt.id,0);//eOpen(objIt);
                                        if(offset==-1)
                                            return -1;
                                    }
                                    offset=Do_no_res(objlist,tasklist,9,id,*it);//eTakeOut(id,objIt);
                                    if(offset==-1)
                                        return -1;
                                }
                            }
                        }
                    }
                }
            }
            else
            {

                Object& target=getObj_id(objlist,tasklist,id);
                if(target!=*Object::NULLObj)
                {
                    target.location=65535;
                }
                if(true==NEWPLAN)
                {
                    return -10;
                }
                askLoc_id(objlist,tasklist,id);
                offset=cPickUp_no_res(objlist,tasklist,id);
                if(offset==-1)
                    return -1;
                if(-10==offset)
                    return -10;
            }
        }
    }
    return offset;
}

int TeamName::cPutDown_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    unsigned int targetNum=65535;
    unsigned  int targetNum_Sense=65535;
    vector<unsigned int> target_choose_vector;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=4;
    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);

    if(targetObj!=*Object::NULLObj)
    {

        targetNum=ChooseObj(objlist,tasklist,mytask);
        mytask.m_first=targetNum;

        if(targetNum!=65535)
            offset=cPutDown_no_res(objlist,tasklist,targetNum);
        else
            return -3;


        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutDown_no_res(objlist,tasklist,mytask);
            return offset;
        }

        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_Sense(objlist,tasklist,mytask);
            if(targetNum_Sense!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum;
            }
            else
            {

            }
            offset=cPutDown_no_res(objlist,tasklist,targetNum);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutDown_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum).hold_locked=2;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}
int TeamName::cPutDown_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    const unsigned int actionNum=3;
    int offset=0;
    unsigned int temp;



    if(objlist.bot.hold==id)//东西在手中时   直接放下
    {

        offset=Do_no_res(objlist,tasklist,3,id,0);//ePutDown(id);
        if(offset==-1)
            return -1;
    }
    else if(objlist.bot.plate==id)//东西在盘子中时
    {
        if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
        {
            temp=objlist.bot.hold;
            offset=Do_no_res(objlist,tasklist,3,temp,0);//ePutDown(hold);
            if(offset==-1)
                return -1;
            offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(plate);
            if(offset==-1)
                return -1;
            offset=Do_no_res(objlist,tasklist,3,id,0);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
        else
        {
            offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(plate);
            if(offset==-1)
                return -1;
            offset=Do_no_res(objlist,tasklist,3,id,0);//ePutDown(hold);
            if(offset==-1)
                return -1;
        }
    }
    return offset;
}

int TeamName::cPutOn_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{

    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=2;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector_backup);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;
        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cPutOn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutOn_no_res(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector_backup);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cPutOn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutOn_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPutOn_no_res(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId)
{
    const unsigned int actionNum=2;
    int offset=0;
    unsigned int continerId;

    offset=cPickUp_no_res(objlist,tasklist,id);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;

    offset=cGoto_no_res(objlist,tasklist,bigId);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;

    offset=cPutDown_no_res(objlist,tasklist,id);
    if(offset==-1)
        return -1;
    if(-10==offset)
        return -10;
    //cout<<"xx:"<<offset<<endl;
    return offset;
}

int TeamName::cPutIn_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    vector<C_para_2>::iterator toErase;
    mytask.is_doing=true;
    C_para_2 targetNum;
    C_para_2 targetNum_Sense;
    vector<C_para_2> target_choose_vector;
    C_para_2 toUpload;

    int offset=0;
    bool continueFlag=false;
    bool done_flag=false;
    const unsigned int actionNum=7;

    Object& targetObj=getObj_Task_idStr(objlist,tasklist,mytask,mytask.firstVar);
    Object& targetObj_c=getObj_Task_idStr(objlist,tasklist,mytask,mytask.secondVar);
    if(targetObj!=*Object::NULLObj)
    {
        targetNum=ChooseObj_big(objlist,tasklist,mytask.m_answer_vector_backup);
        mytask.m_first=targetNum.x;
        mytask.m_second=targetNum.y;


        if(targetNum.x!=65535&&targetNum.y!=65535)
            offset=cPutIn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
        else
            return -3;
        if(offset==-1)
        {
            toErase=mytask.m_answer_vector_backup.end();
            for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
            {
                if(it->x==targetNum.x&&it->y==targetNum.y)
                {
                    toErase=it;
                    break;
                }
            }
            if(toErase!=mytask.m_answer_vector_backup.end())
            {
                mytask.m_answer_vector_backup.erase(toErase);
            }
            mytask.is_doing=false;
            offset=cPutIn_no_res(objlist,tasklist,mytask);
            return offset;
        }
        while(-10==offset)
        {
            //debug insert
            InsertTask(objlist,tasklist);
            targetNum_Sense=ChooseObj_big_Sense(objlist,tasklist,mytask.m_answer_vector_backup);
            if(targetNum_Sense.x!=65535)
            {
                targetNum=targetNum_Sense;
                mytask.m_first=targetNum.x;
                mytask.m_second=targetNum.y;
            }
            else
            {

            }
            offset=cPutIn_no_res(objlist,tasklist,targetNum.x,targetNum.y);
            if(offset==-1)
            {
                toErase=mytask.m_answer_vector_backup.end();
                for(vector<C_para_2>::iterator it=mytask.m_answer_vector_backup.begin();it!=mytask.m_answer_vector_backup.end();it++)
                {
                    if(it->x==targetNum.x&&it->y==targetNum.y)
                    {
                        toErase=it;
                        break;
                    }
                }
                if(toErase!=mytask.m_answer_vector_backup.end())
                {
                    mytask.m_answer_vector_backup.erase(toErase);
                }
                mytask.is_doing=false;
                offset=cPutIn_no_res(objlist,tasklist,mytask);
                return offset;
            }
        }
        getObj_id(objlist,tasklist,targetNum.x).is_locked=true;
        mytask.is_done=true;
    }
    mytask.is_doing=false;
    return offset;
}

int TeamName::cPutIn_no_res(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId)
{
    const unsigned int actionNum=7;
    int offset=0;
    unsigned int inContinerId;
    inContinerId=inContiner_id(objlist,tasklist,id,0);
    Object& obj=getObj_id(objlist,tasklist,id);

    if(inContinerId!=continerId)
    {
        offset=cPickUp_no_res(objlist,tasklist,id);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;

        if(objlist.bot.plate==id)
        {
            if(objlist.bot.hold==0)
            {
                offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(id)
            }
            else
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold)
                offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(id)
            }
        }

        offset=cGoto_no_res(objlist,tasklist,continerId);
        if(offset==-1)
            return -1;
        if(offset==-10)
            return -10;

        if(objlist.bot.plate==id)
        {
            if(objlist.bot.hold==0)
            {
                offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(id)
                if(offset==-1)
                    return -1;
            }
            else
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(hold)
                offset=Do_no_res(objlist,tasklist,5,id,0);//eFromPlate(id)
                if(offset==-1)
                    return -1;
            }
        }


        if(1!=getObj_id(objlist,tasklist,continerId).is_open)
        {
            if(objlist.bot.hold==id)
            {
                offset=Do_no_res(objlist,tasklist,3,id,0);//ePutDown(id);
                if(offset==-1)
                    return -1;
                Object& contain=getObj_id(objlist,tasklist,continerId);
                if(contain!=*Object::NULLObj)
                {
                    if(contain.is_open!=1)
                    {
                        offset=Do_no_res(objlist,tasklist,6,continerId,0);//eOpen(contin);
                        if(offset==-1)
                            return -1;
                    }
                }
                offset=Do_no_res(objlist,tasklist,2,id,0);//ePickUp(id);
                if(offset==-1)
                    return -1;
            }
            else if(objlist.bot.hold!=0)
            {
                offset=Do_no_res(objlist,tasklist,3,objlist.bot.hold,0);//ePutDown(id);
                    if(offset==-1)
                        return -1;
                Object& contain=getObj_id(objlist,tasklist,continerId);
                if(contain!=*Object::NULLObj)
                {
                    if(contain.is_open!=1)
                    {
                        offset=Do_no_res(objlist,tasklist,6,continerId,0);//eOpen(contin);
                        if(offset==-1)
                            return -1;
                    }
                }
                offset=Do_no_res(objlist,tasklist,5,objlist.bot.plate,0);//eFromPlate(plate);
                    if(offset==-1)
                        return -1;

            }
        }
        offset=Do_no_res(objlist,tasklist,8,id,continerId);//ePutIn(id,continerId);
        if(offset==-1)
            return -1;
    }

    return offset;
}




/*action_no_res*/






int TeamName::askLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    //sense map
    bool sense_map_flag=false;
    if(objlist.m_big_obj_number<BIGOBJ&&objlist.m_big_obj_id_vector.size()!=0)
    {
        for(vector<unsigned int>::iterator it=objlist.m_big_obj_id_vector.begin();it!=objlist.m_big_obj_id_vector.end();it++)
        {
            //
            Object& bigObj_temp=getObj_id(objlist,tasklist,*it);
            if(bigObj_temp==*Object::NULLObj)
            {
                continue;
            }

            cGoto(objlist,tasklist,*it,false);

	    if(bigObj_temp.type=="container")
            {
                cOpen(objlist,tasklist,*it,false);
            }


            objlist.m_big_obj_id_vector.erase(it);
            it=objlist.m_big_obj_id_vector.begin();
            if( eSense(objlist,tasklist,id)==id  )
            {
                return objlist.bot.loc;
            }
        }
    }


    if(debug)
        cout<<"askLoc ask"<<endl;
    unsigned int loc=0;
    string info=AskLoc(id);
    string infoStr;
    unsigned int first;
    unsigned int second;

    int flag=0;
    for(vector<string>::iterator it=askInformation::box.begin();it!=askInformation::box.end();it++)
    {
        if(!info.compare(*it))
        {
            flag=1;
        }
    }
    if(flag!=1&&info!="not_known"&&info!="")
    {
        //info=AskLoc(id);
        askInformation::box.push_back(info);
        if(info!="not_known")
        {
            boost::regex reg;
            boost::smatch mat;

            reg=boost::regex("\\w+");
            boost::regex_search(info,mat,reg);
            infoStr=mat[0];

            reg=boost::regex("(?<=\\()\\d+");
            boost::regex_search(info,mat,reg);
            first=stoi(mat[0]);

            reg=boost::regex("(?<=,)\\d+");
            boost::regex_search(info,mat,reg);
            second=stoi(mat[0]);

            getObj_id(objlist,tasklist,id).is_asked=true;

            if("near"==infoStr)
            {
                //getObj_id(objlist,tasklist,second).inside_id.push_back(first);
                loc=getObjLoc_id(objlist,tasklist,second);
            }
            else if("inside"==infoStr)
            {
                getObj_id(objlist,tasklist,second).inside_id.push_back(first);
                getObj_id(objlist,tasklist,first).is_inside=second;
                loc=getObjLoc_id(objlist,tasklist,second);
            }
            else if("on"==infoStr)
            {
                getObj_id(objlist,tasklist,second).on_id.push_back(first);
                getObj_id(objlist,tasklist,first).is_on=second;
                loc=getObjLoc_id(objlist,tasklist,second);
            }
            else if("at"==infoStr)
            {
                getObj_id(objlist,tasklist,first).location=second;
                loc=second;
            }
        }
        else
        {
            loc=askLoc_id(objlist,tasklist,id);
        }
    }
    else
    {
        loc=askLoc_id(objlist,tasklist,id);
    }
    return loc;
}


int TeamName::findObj(ObjectList& objlist,taskList& tasklist,myTask& mytask,int flag)
{
    return 0;
}
int TeamName::getObjLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    unsigned int loc=0;
    unsigned int tempId;
    for(auto it=objlist.obj.begin();it!=objlist.obj.end();it++)
    {
        if(objlist.bot.plate==id||objlist.bot.hold==id)
        {
            loc=objlist.bot.loc;
            break;
        }
        else if(it->id==id)
        {
            loc=it->location;
            if(65535==loc)
            {
                if(it->is_inside!=65535)
                {
                    tempId=it->is_inside;
                    loc=getObjLoc_id(objlist,tasklist,tempId);
                }
                else if(it->is_on!=65535)
                {
                    loc=getObjLoc_id(objlist,tasklist,it->is_on);
                }
                else if(it->near.size()!=0)
                {
                    for(vector<unsigned int>::iterator it_i=it->near.begin();it_i!=it->near.end();it_i++)
                    {
                        loc=getObjLoc_id(objlist,tasklist,*it_i);
                        if(loc!=65535)
                            break;
                    }
                }
                else
                {
                    loc=askLoc_id(objlist,tasklist,id);
                }
            }
            break;
        }
    }

    return loc;
}


int TeamName::getObjLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id,int i_para)
{
    unsigned int loc=65535;
    unsigned int tempId;
    for(auto it=objlist.obj.begin();it!=objlist.obj.end();it++)
    {
        if(objlist.bot.plate==id||objlist.bot.hold==id)
        {
            loc=objlist.bot.loc;
            break;
        }
        else if(it->id==id)
        {
            loc=it->location;
            if(65535==loc)
            {
                if(it->is_inside!=65535)
                {
                    tempId=it->is_inside;
                    loc=getObjLoc_id(objlist,tasklist,tempId);
                }
                else if(it->is_on!=65535)
                {
                    loc=getObjLoc_id(objlist,tasklist,it->is_on);
                }
                else if(it->near.size()!=0)
                {
                    for(vector<unsigned int>::iterator it_i=it->near.begin();it_i!=it->near.end();it_i++)
                    {
                        loc=getObjLoc_id(objlist,tasklist,*it_i);
                        if(loc!=65535)
                            break;
                    }
                }
            }
            break;
        }
    }

    return loc;
}

int TeamName::getObjId_name(ObjectList& objlist,taskList& tasklist,string sortName)
{
    for(auto it=objlist.obj.begin();it!=objlist.obj.end();it++)
    {
        if(it->name==sortName)
        {
            return it->id;
        }
    }
    return -1;
}

Object& TeamName::getObj_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    for(auto it=objlist.obj.begin();it!=objlist.obj.end();it++)
    {
        if(it->id==id)
        {
            return (*it);
        }
    }
    return *Object::NULLObj;
}

bool TeamName::can_at_id_loc(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int loc)
{
    unsigned int loc_no=65535;

    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notInfo.begin();itvInfo!=tasklist.cons_notInfo.end();itvInfo++)
    {
        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            for(vector<unsigned int>::iterator itv=itInfo->answer_vectorId.begin();itv!=itInfo->answer_vectorId.end();itv++)
            {
                if(*itv==id)
                {
                    for(vector<string>::iterator itNear_str=itInfo->near_str.begin();itNear_str!=itInfo->near_str.end();itNear_str++)
                    {
                        Object& second=getObj_Info_idStr(objlist,tasklist,*itvInfo,*itNear_str);
                        for(vector<unsigned int>::iterator itv2=second.answer_vectorId.begin();itv2!=second.answer_vectorId.end();itv2++)
                        {
                            loc_no=getObjLoc_id(objlist,tasklist,*itv2);
                            if(loc_no==loc)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}


bool TeamName::can_plate_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notInfo.begin();itvInfo!=tasklist.cons_notInfo.end();itvInfo++)
    {
        for(vector<unsigned int>::iterator itp=itvInfo->bot.answer_plate.begin();itp!=itvInfo->bot.answer_plate.end();itp++)
        {
            if(*itp==id)
            {
                return false;
            }
        }
    }
    return true;
}

bool TeamName::can_open_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notInfo.begin();itvInfo!=tasklist.cons_notInfo.end();itvInfo++)
    {
        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            if(itInfo->is_open==1)
            {
                for(vector<unsigned int>::iterator itv2=itInfo->answer_vectorId.begin();itv2!=itInfo->answer_vectorId.end();itv2++)
                {
                    if(*itv2==id)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

bool TeamName::can_close_id(ObjectList& objlist,taskList& tasklist,unsigned int id)
{
    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notInfo.begin();itvInfo!=tasklist.cons_notInfo.end();itvInfo++)
    {
        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            if(itInfo->is_open==0)
            {
                for(vector<unsigned int>::iterator itv2=itInfo->answer_vectorId.begin();itv2!=itInfo->answer_vectorId.end();itv2++)
                {
                    if(*itv2==id)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}



int TeamName::inContiner_id(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId)
{
    //debug
    int result=0;
    unsigned int is_inside_temp=getObj_id(objlist,tasklist,id).is_inside;
    if(objlist.bot.hold==id||objlist.bot.plate==id)
    {
        result=0;
    }
    else if(65535!=is_inside_temp)
    {
        result=is_inside_temp;
    }
    else if(getObj_id(objlist,tasklist,id).is_asked==false&&getObj_id(objlist,tasklist,id).location!=65535)
    {
        result=0;
    }
    else if(getObj_id(objlist,tasklist,id).is_asked==false)
    {
        if(debug)
        {
            int x=getObj_id(objlist,tasklist,id).is_asked;
            cout<<"inContiner_id ask"<<endl;
            cout<<int(getObj_id(objlist,tasklist,id).is_asked)<<endl;
        }
        string info=AskLoc(id);
        string infoStr;
        unsigned int first;
        unsigned int second;
        bool flag=false;

        for(vector<string>::iterator it=askInformation::box.begin();it!=askInformation::box.end();it++)
        {
            if(*it==info)
            {
                flag=true;
            }
        }

        if(false==flag&&info!="not_known")
        {
            askInformation::box.push_back(info);
            if(info!="not_known")
            {
                boost::regex reg;
                boost::smatch mat;

                reg=boost::regex("\\w+");
                boost::regex_search(info,mat,reg);
                infoStr=mat[0];

                reg=boost::regex("(?<=\\()\\d+");
                boost::regex_search(info,mat,reg);
                first=stoi(mat[0]);

                reg=boost::regex("(?<=,)\\d+");
                boost::regex_search(info,mat,reg);
                second=stoi(mat[0]);

                getObj_id(objlist,tasklist,id).is_asked=true;

                if("near"==infoStr)
                {
                    getObj_id(objlist,tasklist,second).near.push_back(first);
                    //getObj_id(objlist,tasklist,second).near=first;
                    //loc=getObjLoc_id(objlist,tasklist,second);
                }
                else if("inside"==infoStr)
                {
                    getObj_id(objlist,tasklist,second).inside_id.push_back(first);
                    getObj_id(objlist,tasklist,first).is_inside=second;
                    //loc=getObjLoc_id(objlist,tasklist,second);
                }
                else if("on"==infoStr)
                {
                    getObj_id(objlist,tasklist,second).on_id.push_back(first);
                    getObj_id(objlist,tasklist,first).is_on=second;
                    //loc=getObjLoc_id(objlist,tasklist,second);
                }
                else if("at"==infoStr)
                {
                    getObj_id(objlist,tasklist,first).location=second;
                }

                if("inside"==infoStr)
                {
                    result=second;
                }
                else
                {
                    result=0;
                }
            }
            else
            {
                result=inContiner_id(objlist,tasklist,id,continerId);
            }
        }
        else
        {
            result=inContiner_id(objlist,tasklist,id,continerId);
        }
    }
    else
    {
        result=0;
    }
    return result;
}

int TeamName::resHandler_nnInfo(ObjectList& objlist,taskList& tasklist,int remain_hold)
{
        for(vector<ObjectList>::iterator itnnInfo=tasklist.cons_notnotInfo.begin();itnnInfo!=tasklist.cons_notnotInfo.end();itnnInfo++)
        {
            if(itnnInfo->bot.hold_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,itnnInfo->bot.hold_str);
                if(second!=*Object::NULLObj)
                {
                    for(vector<unsigned int>::iterator itId=second.answer_vectorId.begin();itId!=second.answer_vectorId.end();itId++)
                    {
                        Object& target=getObj_id(objlist,tasklist,*itId);
                        if(target!=*Object::NULLObj)
                        {
                            target.is_locked=true;
                        }
                    }
                }
            }


            for(vector<Object>::iterator infoObj=itnnInfo->obj.begin();infoObj!=itnnInfo->obj.end();infoObj++)
            {
                ////////////////////////////////////////////////////////
                if(infoObj->is_inside_str!="")
                {
                    for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                    {
                        Object& target=getObj_id(objlist,tasklist,*itFirstId);
                        if(target!=*Object::NULLObj)
                        {
                            target.is_locked=true;
                        }
                    }
                }


                if(infoObj->is_on_str!="")
                {
                    for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                    {
                        Object& target=getObj_id(objlist,tasklist,*itFirstId);
                        if(target!=*Object::NULLObj)
                        {
                            target.is_locked=true;
                        }
                    }
                }



                //debug near
                if(0!=infoObj->near_str.size())
                {
                    for(vector<string>::iterator itStr=infoObj->near_str.begin();itStr!=infoObj->near_str.end();itStr++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            Object& first=getObj_id(objlist,tasklist,*itFirstId);
                            if(first==*Object::NULLObj)
                            {
                                continue;
                            }
                            if(first.size==2)
                            {
                                continue;
                            }
                            Object& target=getObj_id(objlist,tasklist,*itFirstId);
                            if(target!=*Object::NULLObj)
                            {
                                target.is_locked=true;
                            }
                        }

                    }
                }


                if(infoObj->is_open!=65535)
                {
                    for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                    {
                        Object& target=getObj_id(objlist,tasklist,*itFirstId);
                        if(target!=*Object::NULLObj)
                        {
                            target.is_locked=true;
                        }
                    }
                }

                if(infoObj->location_str!="")
                {
                    for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                    {
                        Object& target=getObj_id(objlist,tasklist,*itFirstId);
                        if(target!=*Object::NULLObj)
                        {
                            target.is_locked=true;
                        }
                    }
                }






                ////////////////////////////////////////////////////////
            }
        }

    return 0;
}


int TeamName::resHandler_nnInfo(ObjectList& objlist,taskList& tasklist)
{
    for(vector<ObjectList>::iterator itnnInfo=tasklist.cons_notnotInfo.begin();itnnInfo!=tasklist.cons_notnotInfo.end();itnnInfo++)
    {
        if(itnnInfo->bot.plate_str!="")
        {
            Object& plateList=getObj_Info_idStr(objlist,tasklist,*itnnInfo,itnnInfo->bot.plate_str);
            if(plateList!=*Object::NULLObj)
            {
                for(vector<unsigned int>::iterator itPlate=plateList.answer_vectorId.begin();itPlate!=plateList.answer_vectorId.end();itPlate++)
                {
                    Object& plateObj=getObj_id(objlist,tasklist,*itPlate);
                    if(plateObj!=*Object::NULLObj)
                    {
                        plateObj.hold_locked=1;
                    }
                }
            }
        }
        for(vector<Object>::iterator infoObj=itnnInfo->obj.begin();infoObj!=itnnInfo->obj.end();infoObj++)
        {
            ////////////////////////////////////////////////////////
            if(infoObj->is_inside_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->is_inside_str);
                if(second!=*Object::NULLObj)
                {
                    //if(1==second.answer_vectorId.size())
                    for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            //cPutIn(objlist,tasklist,*itFirstId,second.answer_vectorId[0],4);
                            Object& toLock=getObj_id(objlist,tasklist,*itFirstId);
                            if(toLock.is_inside==*itSecondId)
                            {
                                if(toLock!=*Object::NULLObj)
                                {
                                    toLock.is_locked=true;
                                    toLock.hold_locked=2;
                                }
                            }
                        }
                    }
                }
            }

            //edit
            if(infoObj->is_on_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->is_on_str);
                if(second!=*Object::NULLObj)
                {
                    //if(1==second.answer_vectorId.size())
                    for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            //cPutOn(objlist,tasklist,*itFirstId,second.answer_vectorId[0],4);
                            Object& toLock=getObj_id(objlist,tasklist,*itFirstId);
                            if(toLock.location==getObj_id(objlist,tasklist,*itSecondId).location)
                            {
                                if(toLock!=*Object::NULLObj)
                                {
                                    toLock.is_locked=true;
                                    toLock.hold_locked=2;
                                }
                            }
                        }
                    }
                }
            }



            //debug near
            if(0!=infoObj->near_str.size())
            {
                for(vector<string>::iterator itStr=infoObj->near_str.begin();itStr!=infoObj->near_str.end();itStr++)
                {
                    Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,*itStr);
                    if(second!=*Object::NULLObj)
                    {
                        if(1==second.answer_vectorId.size())
                        {
                            for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                            {
                                Object& first=getObj_id(objlist,tasklist,*itFirstId);
                                if(first==*Object::NULLObj)
                                {
                                    continue;
                                }
                                if(first.size==2)
                                {
                                    continue;
                                }
                                first.is_locked=1;
                            }
                        }
                    }
                }
            }


            if(infoObj->is_open!=65535)
            {
                for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                {
                    Object& toLock=getObj_id(objlist,tasklist,*itFirstId);
                    if(toLock!=*Object::NULLObj)
                    {
                        toLock.is_locked=true;
                    }
                }
            }


            if(infoObj->location_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->location_str);
                if(second!=*Object::NULLObj)
                {
                    for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                    {
                        for(vector<unsigned int>::iterator itLoc=second.answer_vectorId.begin();itLoc!=second.answer_vectorId.end();itLoc++)
                        {
                            Object& toLock=getObj_id(objlist,tasklist,*itFirstId);
                            if(toLock!=*Object::NULLObj)
                            {
                                toLock.is_locked=true;
                            }
                        }
                    }
                }
            }

            ////////////////////////////////////////////////////////
        }
    }
    return 0;
}

int TeamName::resHandler_nInfo(ObjectList& objlist,taskList& tasklist)
{
    struct no_task* item;
    for(vector<ObjectList>::iterator itnnInfo=tasklist.cons_notInfo.begin();itnnInfo!=tasklist.cons_notInfo.end();itnnInfo++)
    {
        if(itnnInfo->bot.hold_str!="")
        {
            Object& holdList=getObj_Info_idStr(objlist,tasklist,*itnnInfo,itnnInfo->bot.hold_str);
            if(holdList!=*Object::NULLObj)
            {
                for(vector<unsigned int>::iterator itHold=holdList.answer_vectorId.begin();itHold!=holdList.answer_vectorId.end();itHold++)
                {
                    Object& holdObj=getObj_id(objlist,tasklist,*itHold);
                    if(holdObj!=*Object::NULLObj)
                    {
                        item=new no_task();
                        item->action=5;
                        holdObj.no_action.push_back(*item);
                        holdObj.hold_locked=2;
                        delete item;
                    }
                }
            }
        }
        if(itnnInfo->bot.plate_str!="")
        {
            Object& plateList=getObj_Info_idStr(objlist,tasklist,*itnnInfo,itnnInfo->bot.plate_str);
            if(plateList!=*Object::NULLObj)
            {
                for(vector<unsigned int>::iterator itPlate=plateList.answer_vectorId.begin();itPlate!=plateList.answer_vectorId.end();itPlate++)
                {
                    Object& plateObj=getObj_id(objlist,tasklist,*itPlate);
                    if(plateObj!=*Object::NULLObj)
                    {
                        item=new no_task();
                        item->action=10;
                        plateObj.no_action.push_back(*item);
                        plateObj.hold_locked=2;
                        delete item;
                    }
                }
            }
        }

        for(vector<Object>::iterator infoObj=itnnInfo->obj.begin();infoObj!=itnnInfo->obj.end();infoObj++)
        {
            ////////////////////////////////////////////////////////
            if(infoObj->is_inside_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->is_inside_str);
                if(second!=*Object::NULLObj)
                {
                    for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            //cPutIn(objlist,tasklist,*itFirstId,second.answer_vectorId[0],4);
                            Object& firstObj=getObj_id(objlist,tasklist,*itFirstId);
                            item=new no_task();
                            item->action=7;
                            item->actionId=*itSecondId;
                            firstObj.no_action.push_back(*item);
                            delete item;
                        }
                    }
                }
            }


            if(infoObj->is_on_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->is_on_str);
                if(second!=*Object::NULLObj)
                {
                    for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            //cPutOn(objlist,tasklist,*itFirstId,second.answer_vectorId[0],4);
                            Object& firstObj=getObj_id(objlist,tasklist,*itFirstId);
                            item=new no_task();
                            item->action=2;
                            item->actionId=*itSecondId;
                            firstObj.no_action.push_back(*item);
                            delete item;
                        }
                    }
                }
            }



            //debug near
            if(0!=infoObj->near_str.size())
            {
                for(vector<string>::iterator itStr=infoObj->near_str.begin();itStr!=infoObj->near_str.end();itStr++)
                {
                    Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,*itStr);
                    if(second!=*Object::NULLObj)
                    {
                        for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                        {
                            for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                            {
                                Object& firstObj=getObj_id(objlist,tasklist,*itFirstId);
                                item=new no_task();
                                item->action=2;
                                item->actionId=*itSecondId;
                                firstObj.no_action.push_back(*item);
                                delete item;
                            }
                        }
                    }
                }
            }


            if(infoObj->is_open!=65535)
            {

                for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                {
                    Object& toLock=getObj_id(objlist,tasklist,*itFirstId);
                    if(toLock!=*Object::NULLObj)
                    {
                        toLock.is_locked=true;
                        toLock.keep_door=1;
                    }
                }
            }

            if(infoObj->location_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itnnInfo,infoObj->location_str);
                if(second!=*Object::NULLObj)
                {
                    for(vector<unsigned int>::iterator itSecondId=second.answer_vectorId.begin();itSecondId!=second.answer_vectorId.end();itSecondId++)
                    {
                        for(vector<unsigned int>::iterator itFirstId=infoObj->answer_vectorId.begin();itFirstId!=infoObj->answer_vectorId.end();itFirstId++)
                        {
                            //cPutOn(objlist,tasklist,*itFirstId,second.answer_vectorId[0],4);
                            Object& firstObj=getObj_id(objlist,tasklist,*itFirstId);
                            item=new no_task();
                            item->action=2;
                            item->actionId=*itSecondId;
                            firstObj.no_action.push_back(*item);
                            delete item;
                        }
                    }
                }
            }



            ////////////////////////////////////////////////////////
        }
    }
    return 0;
}



int TeamName::answer_info(ObjectList& objlist,taskList& tasklist)//working
{
    for(vector<ObjectList>::iterator itvInfo=tasklist.info.begin();itvInfo!=tasklist.info.end();itvInfo++)
    {

        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            itInfo->answer_vectorId.clear();
            for(auto itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
            {
                if(itInfo->compare(*itObj))
                {
                    itInfo->answer_vectorId.push_back(itObj->id);
                }
            }
        }

    }


    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notInfo.begin();itvInfo!=tasklist.cons_notInfo.end();itvInfo++)
    {
        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            itInfo->answer_vectorId.clear();
            for(auto itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
            {
                if(itInfo->compare(*itObj))
                {
                    itInfo->answer_vectorId.push_back(itObj->id);
                }
            }
        }

    }


    for(vector<ObjectList>::iterator itvInfo=tasklist.cons_notnotInfo.begin();itvInfo!=tasklist.cons_notnotInfo.end();itvInfo++)
    {

        for(vector<Object>::iterator itInfo=itvInfo->obj.begin();itInfo!=itvInfo->obj.end();itInfo++)
        {
            itInfo->answer_vectorId.clear();
            for(auto itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
            {
                if(itInfo->compare(*itObj))
                {
                    itInfo->answer_vectorId.push_back(itObj->id);
                }
            }
        }

    }
    return 0;
}

int TeamName::answer_task(ObjectList& objlist,taskList& tasklist)//working
{
    for(vector<myTask>::iterator itvTask=tasklist.task.begin();itvTask!=tasklist.task.end();itvTask++)
    {
        for(vector<Object>::iterator itTask=itvTask->obj.obj.begin();itTask!=itvTask->obj.obj.end();itTask++)
        {
            itTask->answer_vectorId.clear();
            for(auto itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
            {

                if(itTask->compare(*itObj))
                {
                    itTask->answer_vectorId.push_back(itObj->id);
                }
            }
        }

    }

    for(vector<myTask>::iterator itvTask=tasklist.cons_notTask.begin();itvTask!=tasklist.cons_notTask.end();itvTask++)
    {
        if(1==itvTask->action)
        {
            itvTask->firstVar=itvTask->secondVar;
            itvTask->secondVar="human";
        }
        for(vector<Object>::iterator itTask=itvTask->obj.obj.begin();itTask!=itvTask->obj.obj.end();itTask++)
        {
            itTask->answer_vectorId.clear();
            for(auto itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
            {

                if(itTask->compare(*itObj))
                {
                    itTask->answer_vectorId.push_back(itObj->id);
                }
            }
        }

    }

    return 0;
}


Object& TeamName::getObj_Info_idStr(ObjectList& objlist,taskList& tasklist,ObjectList& info,string idStr)
{
    for(auto it=info.obj.begin();it!=info.obj.end();it++)
    {
        if(it->id_str==idStr)
        {
            return (*it);
        }
    }
    return *Object::NULLObj;
}

Object& TeamName::getObj_Task_idStr(ObjectList& objlist,taskList& tasklist,myTask& task,string idStr)
{
    for(auto it=task.obj.obj.begin();it!=task.obj.obj.end();it++)
    {
        if(it->id_str==idStr)
        {
            return (*it);
        }
    }
    return *Object::NULLObj;
}

int TeamName::resHandler_nInfo(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId,int remain_hold)
{
    Object& first=getObj_id(objlist,tasklist,firstId);
    Object& second=getObj_id(objlist,tasklist,secondId);


    int done=0;
    switch(actionId)
    {
        case 1:
            //eMove
            for(vector<unsigned int>::iterator itN=objlist.bot.not_go.begin();itN!=objlist.bot.not_go.end();itN++)
            {
                if(*itN==firstId)
                {
                    return -1;
                }
            }
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eMove(firstId);
            if(done==1)
            {
                if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
                {
                    getObj_id(objlist,tasklist,objlist.bot.hold).location=firstId;
                }
                if(objlist.bot.plate!=0&&objlist.bot.plate!=65535)
                {
                    getObj_id(objlist,tasklist,objlist.bot.plate).location=firstId;
                }
                objlist.bot.loc=firstId;
            }
            break;
        case 2:
            //ePickUp
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            if(first!=*Object::NULLObj)
            {
                if(first.is_locked==true)
                    return -1;
                if(first.hold_locked==2)
                    return -1;
                if(first.need_hold!=1)//debug
                {
                    for(vector<no_task>::iterator no_act=first.no_action.begin();no_act!=first.no_action.end();no_act++)
                    {
                        if(no_act->action==4)
                            return -1;
                    }
                }
                if(first.hold_locked==1)
                    {
                        if(first.need_hold!=1)
                            return -1;
                    }
            }
            done=ePickUp(firstId);
            if(done==1)
            {
                objlist.bot.hold=firstId;
            }
            break;
        case 3:
            //ePutDown
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            if(first!=*Object::NULLObj)
            {
                if(first.hold_locked==1)
                    return -1;
            }
            done=ePutDown(firstId);
            if(1==done)
            {
                objlist.bot.hold=0;
                first.sensed=true;
            }
            break;
        case 4:
            //eToPlate
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=eToPlate(firstId);
            if(1==done)
            {
                objlist.bot.plate=firstId;
                objlist.bot.hold=0;
            }
            else
            {
                done=false;
            }
            break;
        case 5:
            //eFromPlate
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=eFromPlate(firstId);
            if(1==done)
            {
                objlist.bot.hold=objlist.bot.plate;
                objlist.bot.plate=0;
            }
            break;
        case 6:
            //eOpen
            //working
            if(first!=*Object::NULLObj)
            {
                if(first.keep_door==1)
                    return -1;
            }
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eOpen(firstId);
            if(1==done)
            {
                getObj_id(objlist,tasklist,firstId).is_open=1;
            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_open=1;
            }
            break;
        case 7:
            //eClose
            if(first!=*Object::NULLObj)
            {
                if(first.keep_door==1)
                    return -1;
            }
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eClose(firstId);
            if(1==done)
            {
                getObj_id(objlist,tasklist,firstId).is_open=2;
            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_open=2;
            }
            break;
        case 8:
            //ePutIn
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=ePutIn(firstId,secondId);
            if(1==done)
            {
                objlist.bot.hold=0;
                getObj_id(objlist,tasklist,firstId).is_inside=secondId;
                getObj_id(objlist,tasklist,secondId).inside_id.push_back(firstId);
            }
            break;
        case 9:
            //eTakeOut
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;

            if(first!=*Object::NULLObj)
            {
                if(second!=*Object::NULLObj)
                {

                    if(first.is_locked==true)
                        return -1;
                    if(first.hold_locked==2)
                        return -1;
                    if(first.hold_locked!=1)
                    {
                        for(vector<no_task>::iterator no_act=first.no_action.begin();no_act!=first.no_action.end();no_act++)
                        {
                            if(no_act->action==4)
                                return -1;
                            if(no_act->action==9)
                            {
                                if(no_act->actionId==secondId)
                                    return -1;
                            }
                        }
                    }
                    if(first.hold_locked==1)
                    {
                        if(first.need_hold!=1)
                            return -1;
                    }

                }
            }
            done=eTakeOut(firstId,secondId);

            bool findFlag=false;
            vector<unsigned int>::iterator eraseIt;
            Object& secObj=getObj_id(objlist,tasklist,secondId);
            for(vector<unsigned int>::iterator it=secObj.inside_id.begin();it!=secObj.inside_id.end();it++)
            {
                if(*it==firstId)
                {
                    eraseIt=it;
                    findFlag=true;
                    break;
                }
            }
            if(findFlag)
            {
                if(eraseIt!=secObj.inside_id.end())
                {
                    secObj.inside_id.erase(eraseIt);
                }
            }
            else
            {
                if(debug)
                    cout<<"resHandler_nInfo TakeOut debug"<<endl;
            }

            if(1==done)
            {
                objlist.bot.hold=firstId;
                getObj_id(objlist,tasklist,firstId).is_inside=0;

            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_inside=65535;
            }
            break;
    }

    return done;
}


int TeamName::Do_no_res(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId)
{
    Object& first=getObj_id(objlist,tasklist,firstId);
    Object& second=getObj_id(objlist,tasklist,secondId);


    int done=0;
    switch(actionId)
    {
        case 1:
            //eMove
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eMove(firstId);
            if(done==1)
            {
                if(objlist.bot.hold!=0&&objlist.bot.hold!=65535)
                {
                    getObj_id(objlist,tasklist,objlist.bot.hold).location=firstId;
                }
                if(objlist.bot.plate!=0&&objlist.bot.plate!=65535)
                {
                    getObj_id(objlist,tasklist,objlist.bot.plate).location=firstId;
                }
                objlist.bot.loc=firstId;
            }
            break;
        case 2:
            //ePickUp
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            if(first!=*Object::NULLObj)
            {
                if(first.is_locked==true)
                    return -1;
                if(first.hold_locked==2)
                    return -1;
                if(first.hold_locked==1)
                    {
                        if(first.need_hold!=1)
                            return -1;
                    }
            }
            done=ePickUp(firstId);
            if(done==1)
            {
                objlist.bot.hold=firstId;
            }
            break;
        case 3:
            //ePutDown
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            if(first!=*Object::NULLObj)
            {
                if(first.hold_locked==1)
                    return -1;
            }
            done=ePutDown(firstId);
            if(1==done)
            {
                objlist.bot.hold=0;
            }
            break;
        case 4:
            //eToPlate
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=eToPlate(firstId);
            if(1==done)
            {
                objlist.bot.plate=firstId;
                objlist.bot.hold=0;
            }
            else
            {
                done=false;
            }
            break;
        case 5:
            //eFromPlate
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=eFromPlate(firstId);
            if(1==done)
            {
                objlist.bot.hold=objlist.bot.plate;
                objlist.bot.plate=0;
            }
            break;
        case 6:
            //eOpen
            //working
            if(first!=*Object::NULLObj)
            {
                if(first.keep_door==1)
                    return -1;
            }
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eOpen(firstId);
            if(1==done)
            {
                getObj_id(objlist,tasklist,firstId).is_open=1;
            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_open=1;
            }
            break;
        case 7:
            //eClose
            if(first!=*Object::NULLObj)
            {
                if(first.keep_door==1)
                    return -1;
            }
            objlist.bot.here.clear();
            objlist.bot.senseLoc=65535;
            done=eClose(firstId);
            if(1==done)
            {
                getObj_id(objlist,tasklist,firstId).is_open=2;
            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_open=2;
            }
            break;
        case 8:
            //ePutIn
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;
            done=ePutIn(firstId,secondId);
            if(1==done)
            {
                objlist.bot.hold=0;
                getObj_id(objlist,tasklist,firstId).is_inside=secondId;
                getObj_id(objlist,tasklist,secondId).inside_id.push_back(firstId);
            }
            break;
        case 9:
            //eTakeOut
            //objlist.bot.here.clear();
            //objlist.bot.senseLoc=65535;

            if(first!=*Object::NULLObj)
            {
                if(second!=*Object::NULLObj)
                {

                    if(first.is_locked==true)
                        return -1;
                    if(first.hold_locked==2)
                        return -1;
                    if(first.hold_locked==1)
                    {
                        if(first.need_hold!=1)
                            return -1;
                    }

                }
            }
            done=eTakeOut(firstId,secondId);

            bool findFlag=false;
            vector<unsigned int>::iterator eraseIt;
            Object& secObj=getObj_id(objlist,tasklist,secondId);
            for(vector<unsigned int>::iterator it=secObj.inside_id.begin();it!=secObj.inside_id.end();it++)
            {
                if(*it==firstId)
                {
                    eraseIt=it;
                    findFlag=true;
                    break;
                }
            }
            if(findFlag)
            {
                if(eraseIt!=secObj.inside_id.end())
                {
                    secObj.inside_id.erase(eraseIt);
                }
            }
            else
            {
                if(debug)
                    cout<<"resHandler_nInfo TakeOut debug"<<endl;
            }

            if(1==done)
            {
                objlist.bot.hold=firstId;
                getObj_id(objlist,tasklist,firstId).is_inside=0;

            }
            else
            {
                getObj_id(objlist,tasklist,firstId).is_inside=65535;
            }
            break;
    }

    return done;
}

/*class command end  */

/*class step start*/
int TeamName::mission(ObjectList& objlist,taskList& tasklist)
{
    int offset=0;
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        offset=0;
        //cout<<itTask->m_answer_vector.size()<<endl;
        if(itTask->is_done==true)
            continue;
        offset=letsGo(objlist,tasklist,*itTask);
        if(offset==-3)
        {
            itTask->is_ignored=true;
        }
        itTask->is_done=true;
    }
    return 0;
}

int TeamName::mission_no_res(ObjectList& objlist,taskList& tasklist)
{
    int offset=0;
    int ignoreNum=0;
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        if(itTask->is_ignored==true)
        {
            ignoreNum++;
        }
    }

    if(ignoreNum==tasklist.task.size())
    {
        for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
        {
            if(itTask->is_ignored==true)
            {
                offset=letsGo_no_res(objlist,tasklist,*itTask);
                if(offset=-3)
                {
                    itTask->is_ignored=true;
                }
                itTask->is_done=true;
            }
        }
    }


    return 0;
}



int TeamName::letsGo(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    int offset=0;
    switch(mytask.action)
    {
        case 1:
            //give(human,obj1)
            offset=cGive(objlist,tasklist,mytask);
            break;
        case 2:
            //puton(small,big)
            offset=cPutOn(objlist,tasklist,mytask);
            break;
        case 3:
            //goto(obj)
            offset=cGoto(objlist,tasklist,mytask);
            break;
        case 4:
            //putdown(obj)
            offset=cPutDown(objlist,tasklist,mytask);
            break;
        case 5:
            //pickup(obj)
            offset=cPickUp(objlist,tasklist,mytask);
            break;
        case 6:
            //open(obj)
            offset=cOpen(objlist,tasklist,mytask);
            break;
        case 7:
            //putin(id,continer)
            offset=cPutIn(objlist,tasklist,mytask);
            break;
        case 8:
            //close(obj)
            offset=cClose(objlist,tasklist,mytask);
            break;
        case 9:
            //takeout(id,continer)
            offset=cTakeOut(objlist,tasklist,mytask);
            break;
        default:
            if(debug)
                cout<<"task error"<<endl;
            break;
    }
    return offset;
}

int TeamName::letsGo_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask)
{
    int offset=0;
    switch(mytask.action)
    {
        case 1:
            //give(human,obj1)
            offset=cGive_no_res(objlist,tasklist,mytask);
            break;
        case 2:
            //puton(small,big)
            offset=cPutOn_no_res(objlist,tasklist,mytask);
            break;
        case 3:
            //goto(obj)
            offset=cGoto_no_res(objlist,tasklist,mytask);
            break;
        case 4:
            //putdown(obj)
            offset=cPutDown_no_res(objlist,tasklist,mytask);
            break;
        case 5:
            //pickup(obj)
            offset=cPickUp_no_res(objlist,tasklist,mytask);
            break;
        case 6:
            //open(obj)
            offset=cOpen_no_res(objlist,tasklist,mytask);
            break;
        case 7:
            //putin(id,continer)
            offset=cPutIn_no_res(objlist,tasklist,mytask);
            break;
        case 8:
            //close(obj)
            offset=cClose_no_res(objlist,tasklist,mytask);
            break;
        case 9:
            //takeout(id,continer)
            offset=cTakeOut_no_res(objlist,tasklist,mytask);
            break;
        default:
            if(debug)
                cout<<"task error"<<endl;
            break;
    }
    return offset;
}

void TeamName::funPriority(taskList& tasklist)
{
    for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
    {
        switch(itTask->action)
        {
            case 1:
                //give(human,obj1)
                itTask->priority=4;
                break;
            case 2:
                //puton(small,big)
                itTask->priority=4;
                break;
            case 3:
                //goto(obj)
                itTask->priority=7;
                break;
            case 4:
                //putdown(obj)
                itTask->priority=1;
                break;
            case 5:
                //pickup(obj)
                itTask->priority=6;
                break;
            case 6:
                //open(obj)
                itTask->priority=2;
                break;
            case 7:
                //putin(id,continer)
                itTask->priority=4;
                break;
            case 8:
                //close(obj)
                itTask->priority=5;
                break;
            case 9:
                //takeout(id,continer)
                itTask->priority=3;
                break;
            default:
                if(debug)
                    cout<<"task error"<<endl;
                break;
        }
    }
}

int TeamName::supplyObjectList(ObjectList& objlist,taskList& tasklist)
{
    int match_num=0;
    for(vector<Object>::iterator it=objlist.obj.begin();it!=objlist.obj.end();it++)
    {
        match_num=0;
        if(""!=it->name)
        {
            match_num++;
        }
        if(65535!=it->color)
        {
            match_num++;
        }
        it->m_match=match_num;
    }
    for(vector<ObjectList>::iterator itInfo=tasklist.info.begin();itInfo!=tasklist.info.end();itInfo++)
    {
        if(itInfo->bot.plate_str!="")
        {
            Object& plateObjInfo=getObj_Info_idStr(objlist,tasklist,*itInfo,itInfo->bot.plate_str);
            if(plateObjInfo!=*Object::NULLObj)
            {
                if(1==plateObjInfo.answer_vectorId.size())
                {
                    if(65535==objlist.bot.plate)
                    objlist.bot.plate=plateObjInfo.answer_vectorId[0];
                }
                for(vector<unsigned int>::iterator itAnswer=plateObjInfo.answer_vectorId.begin();itAnswer!=plateObjInfo.answer_vectorId.end();itAnswer++)
                {
                    //add debug
                }
            }
        }


        if(itInfo->bot.hold_str!="")
        {
            Object& holdObjInfo=getObj_Info_idStr(objlist,tasklist,*itInfo,itInfo->bot.hold_str);
            if(holdObjInfo!=*Object::NULLObj)
            {
                if(1==holdObjInfo.answer_vectorId.size())
                {
                    if(65535==objlist.bot.hold)
                        objlist.bot.hold=holdObjInfo.answer_vectorId[0];
                }
                for(vector<unsigned int>::iterator itAnswer=holdObjInfo.answer_vectorId.begin();itAnswer!=holdObjInfo.answer_vectorId.end();itAnswer++)
                {
                    //add debug
                }
            }
        }


        for(vector<Object>::iterator itInfoObj=itInfo->obj.begin();itInfoObj!=itInfo->obj.end();itInfoObj++)
        {
            //////////////////////////////////////////
            if(itInfoObj->is_inside_str!="")
            {
                Object& first=getObj_Info_idStr(objlist,tasklist,*itInfo,itInfoObj->is_inside_str);
                if(first!=*Object::NULLObj)
                {
                    if(1==first.answer_vectorId.size())
                    {
                        for(vector<unsigned int>::iterator itSecondObj=itInfoObj->answer_vectorId.begin();itSecondObj!=itInfoObj->answer_vectorId.end();itSecondObj++)
                        {
                            Object& answerObj=getObj_id(objlist,tasklist,*itSecondObj);
                            if(answerObj!=*Object::NULLObj)
                            {
                                if(65535==answerObj.is_inside)
                                {
                                    answerObj.is_inside=first.answer_vectorId[0];
                                }
                            }
                        }
                    }
                }
            }

            if(itInfoObj->is_on_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itInfo,itInfoObj->is_on_str);
                if(second!=*Object::NULLObj)
                {
                    if(1==second.answer_vectorId.size())
                    {
                        for(vector<unsigned int>::iterator itfirstObj=itInfoObj->answer_vectorId.begin();itfirstObj!=itInfoObj->answer_vectorId.end();itfirstObj++)
                        {
                            Object& answerObj=getObj_id(objlist,tasklist,*itfirstObj);
                            if(answerObj!=*Object::NULLObj)
                            {
                                if(65535==answerObj.is_on)
                                {
                                    answerObj.is_on=second.answer_vectorId[0];
                                }
                            }
                        }
                    }
                }
            }

            if(itInfoObj->is_open!=65535)
            {
                for(vector<unsigned int>::iterator itfirstObj=itInfoObj->answer_vectorId.begin();itfirstObj!=itInfoObj->answer_vectorId.end();itfirstObj++)
                {
                    Object& answerObj=getObj_id(objlist,tasklist,*itfirstObj);
                    if(answerObj!=*Object::NULLObj)
                    {
                        if(65535==answerObj.is_open)
                        {
                            answerObj.is_open=itInfoObj->is_open;
                        }
                    }
                }
            }

            if(0!=itInfoObj->near_str.size())
            {
                for(vector<string>::iterator itSecondStr=itInfoObj->near_str.begin();itSecondStr!=itInfoObj->near_str.end();itSecondStr++)
                {
                    Object& second=getObj_Info_idStr(objlist,tasklist,*itInfo,*itSecondStr);
                    if(second!=*Object::NULLObj)
                    {
                        for(vector<unsigned int>::iterator itSecondObj=second.answer_vectorId.begin();itSecondObj!=second.answer_vectorId.end();itSecondObj++)
                        {
                            for(vector<unsigned int>::iterator itFirstObj=itInfoObj->answer_vectorId.begin();itFirstObj!=itInfoObj->answer_vectorId.end();itFirstObj++)
                            {
                                Object& firstObj=getObj_id(objlist,tasklist,*itFirstObj);
                                if(firstObj!=*Object::NULLObj)
                                {
                                    Object& secondObj=getObj_id(objlist,tasklist,*itSecondObj);
                                    if(secondObj!=*Object::NULLObj)
                                    {
                                        firstObj.near.push_back(*itSecondObj);
                                        secondObj.near.push_back(*itFirstObj);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(itInfoObj->location_str!="")
            {
                Object& second=getObj_Info_idStr(objlist,tasklist,*itInfo,itInfoObj->location_str);
                if(second!=*Object::NULLObj)
                {
                    if(1==second.answer_vectorId.size())
                    {
                        for(vector<unsigned int>::iterator itfirstObj=itInfoObj->answer_vectorId.begin();itfirstObj!=itInfoObj->answer_vectorId.end();itfirstObj++)
                        {
                            Object& answerObj=getObj_id(objlist,tasklist,*itfirstObj);
                            if(answerObj!=*Object::NULLObj)
                            {
                                if(65535==answerObj.location)
                                {
                                    //answerObj.location=second.answer_vectorId[0];
                                }
                            }
                        }
                    }
                }
            }







            ////////////////////////////////////////////////////////
        }
    }
    return 0;
}

//working
int TeamName::resHandler_nTask(ObjectList& objlist,taskList& tasklist)
{
    struct no_task* item;
    for(vector<myTask>::iterator itTask=tasklist.cons_notTask.begin();itTask!=tasklist.cons_notTask.end();itTask++)
    {
        Object& firstObj=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->firstVar);
        Object& secondObj=getObj_Task_idStr(objlist,tasklist,*itTask,itTask->secondVar);
        if(firstObj!=*Object::NULLObj)
        {
            for(vector<unsigned int>::iterator itFirst=firstObj.answer_vectorId.begin();itFirst!=firstObj.answer_vectorId.end();itFirst++)
            {

                item=new no_task();
                Object& first=getObj_id(objlist,tasklist,*itFirst);
                //Object& second=getObj_id(objlist,tasklist,*itSecond);
                switch(itTask->action)
                {
                    case 3:
                        //goto(obj)
                    case 4:
                        //putdown(obj)
                    case 5:
                        //pickup(obj)
                    case 6:
                        //open(obj)
                    case 8:
                        //close(obj)
                        if(first!=*Object::NULLObj)
                        {
                            item->action=itTask->action;
                        }
                        break;
                    default:
                        //if(debug)
                        //    cout<<"task error"<<endl;
                        break;
                }

                if(secondObj!=*Object::NULLObj&&secondObj!=firstObj)
                {
                    for(vector<unsigned int>::iterator itSecond=secondObj.answer_vectorId.begin();itSecond!=secondObj.answer_vectorId.end();itSecond++)
                    {
                        Object& second=getObj_id(objlist,tasklist,*itSecond);
                        switch(itTask->action)
                        {
                            case 2:
                                //puton(small,big)
                            case 7:
                                //putin(id,continer)
                            case 9:
                                //takeout(id,continer)
                                if(second!=*Object::NULLObj)
                                {
                                    item->action=itTask->action;
                                    item->actionId=*itSecond;
                                }
                            default:
                                if(debug)
                                    cout<<"task error"<<endl;
                                break;
                        }
                    }
                }
                first.no_action.push_back(*item);
                delete item;
            }
        }
    }

    for(vector<Object>::iterator itObj=objlist.obj.begin();itObj!=objlist.obj.end();itObj++)
    {
        for(vector<struct no_task>::iterator itNoTask=itObj->no_action.begin();itNoTask!=itObj->no_action.end();itNoTask++)
        {
            switch(itNoTask->action)
            {
                case 3:
                    itObj->give_up=1;
                    objlist.bot.not_go.push_back(getObjLoc_id(objlist,tasklist,itObj->id));
                    break;
                case 4:
                    itObj->hold_locked=1;
                    break;
                case 5:
                    itObj->hold_locked=2;
                    itObj->is_locked=true;
                    break;
                case 6:
                case 8:
                    itObj->keep_door=1;
                    itObj->is_locked=true;
                    break;
                case 9:
                    itObj->is_locked=true;
                    break;
                case 10:
                    itObj->need_plate=2;
            }
        }
    }

    return 0;
}

 int TeamName::LoadAction(ObjectList& objlist,taskList& tasklist,C_map& x_map)
 {
     bool continueFlag;
     continueFlag=false;
     C_action_chain* action_chain_cache;
     Object firstObj;
     Object secondObj;

     vector<C_action_chain> action_chain_1vector;
     vector<C_action_chain> do_action_chain_cache;
     vector<unsigned int> max_index;
     vector<unsigned int> index;

     int max_score=-1000;
     int score=0;

     max_index.clear();//小于它
     index.clear();
     action_chain_1vector.clear();

    if(IS_RESERVE)
     {
         max_index.reserve(RESERVE_NUM);
        index.reserve(RESERVE_NUM);
        action_chain_1vector.reserve(RESERVE_NUM);
     }

     for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
     {
         //i_1st_vector.clear();
         //i_2nd_vector.clear();
        for(vector<unsigned int>::iterator itFirst=itTask->obj[itTask->firstVar].answer_vectorId.begin();itFirst!=itTask->obj[itTask->firstVar].answer_vectorId.end();itFirst++)
        {
            for(vector<unsigned int>::iterator itSecond=itTask->obj[itTask->secondVar].answer_vectorId.begin();itSecond!=itTask->obj[itTask->secondVar].answer_vectorId.end();itSecond++)
            {
                continueFlag=false;

                action_chain_cache=new C_action_chain();
                action_chain_cache->m_action_num=itTask->action;
                action_chain_cache->m_1st_obj_num=*itFirst;
                action_chain_cache->m_2nd_obj_num=*itSecond;


                firstObj=getObj_id(objlist,tasklist,*itFirst);
                secondObj=getObj_id(objlist,tasklist,*itSecond);

                if(firstObj!=*Object::NULLObj)
                {
                    if(firstObj.NO==1||firstObj.is_locked==true)
                    {
                        continueFlag=true;
                        //debug3
                    }
                    else
                    {
                        for(vector<struct no_task>::iterator itNoTask=firstObj.no_action.begin();itNoTask!=firstObj.no_action.end();itNoTask++)
                        {
                            //debug3
                            if(itNoTask->action==itTask->action&&itNoTask->actionId==*itSecond)
                            {
                                continueFlag=true;
                            }
                        }
                    }
                }
                else
                {
                    continueFlag=true;
                    delete action_chain_cache;
                    continue;
                }



                //action_chain_cache->m_1st_position=getObjLoc_id(objlist,tasklist,*itFirst);
                //action_chain_cache->m_2nd_position=getObjLoc_id(objlist,tasklist,*itSecond);

                if(continueFlag==true)
                {
                    delete action_chain_cache;
                    continue;
                }

                //C_position::action_chain.push_back(*action_chain_cache);
                if(action_chain_cache->m_action_num==1)
                {
                    action_chain_cache->m_2nd_obj_num=getObjId_name(objlist,tasklist,"human");
                }
                action_chain_cache->m_1st_position=getObjLoc_id(objlist,tasklist,action_chain_cache->m_1st_obj_num,0);
                action_chain_cache->m_2nd_position=getObjLoc_id(objlist,tasklist,action_chain_cache->m_2nd_obj_num,0);
                if(action_chain_cache->m_action_num==1)
                {
                    getObjId_name(objlist,tasklist,"human");
                }
                action_chain_1vector.push_back(*action_chain_cache);

                //i_1st_vector.push_back(*itFirst);
                //i_2nd_vector.push_back(*itSecond);
                delete action_chain_cache;
                //debug2
            }
        }
        //debug now 过滤已经完成的任务
        if(itTask->action==3||itTask->action==5||itTask->action==6||itTask->action==8||itTask->action==4)
        {
            C_position::task_array_door.push_back(action_chain_1vector);
        }
        else
        {
            C_position::task_array.push_back(action_chain_1vector);
        }
        action_chain_1vector.clear();
     }

     for(unsigned int i=0;i<C_position::task_array.size();i++)
     {
         index.push_back(0);
         max_index.push_back(C_position::task_array[i].size());
     }
     index.push_back(0);

     while(index[index.size()-1]==1)
     {
         for(unsigned int i=0;i<max_index.size();i++)
         {
             action_chain_1vector.push_back(C_position::task_array[ i ][ index[ i ] ]);
             //C_position::task_array[ i ][ index[ i ] ] ;
         }

        score=Score_vector(action_chain_1vector);
        if(score>max_score)
        {
            max_score=score;
            do_action_chain_cache.assign(C_position::do_action_chain.begin(),C_position::do_action_chain.end());
            C_position::action_chain.clear();
            C_position::action_chain.assign(action_chain_1vector.begin(),action_chain_1vector.end());
        }
        else
        {
            C_position::do_action_chain.assign(do_action_chain_cache.begin(),do_action_chain_cache.end());
        }

        //debug now

         index[0]+=1;
         for(unsigned int i=0;i<max_index.size();i++)
         {
             if(index[i]>=max_index[i])
             {
                 index[i+1]+=1;
                 index[i]=0;
             }
         }
         action_chain_1vector.clear();
     }

     return 0;
 }

 int TeamName::Score_vector(const vector<C_action_chain>& para_vector)
 {
     int result=0;
     int result_offset=0;
     int max_offset=0;

     vector<vector<C_action_chain>::const_iterator> chain_it_vector;//存储 遍历的序列
     //vector<vector<C_action_chain>::const_iterator> counter_vector;
     bool flag_add=false;
     //it_vector.reserve(10);



    for(vector<C_action_chain>::const_iterator it=para_vector.begin();it!=para_vector.end();it++)
    {
        if(it->m_1st_position!=65535)
            result+=2;
        if(it->m_2nd_position!=65535)
            result+=2;
        chain_it_vector.push_back(para_vector.begin());
        //debug now
    }

    chain_it_vector.push_back(para_vector.begin());


    chain_it_vector[0]=para_vector.begin();
    while(chain_it_vector[chain_it_vector.size()-1]==para_vector.begin())
    {
        for(vector<vector<C_action_chain>::const_iterator>::iterator it=chain_it_vector.begin();it!=chain_it_vector.end()-1;it++)
        {
            for(vector<vector<C_action_chain>::const_iterator>::iterator it2=it+1;it2!=chain_it_vector.end()-1;it2++)
            {
                if(*it2==*it)
                {
                    flag_add=true;
                    break;
                }
            }
            if(flag_add==true)
            {
                break;
            }
        }

        if(flag_add==false)
        {
            //得到目标
            //debug now
            result_offset=0;
            for(vector<vector<C_action_chain>::const_iterator>::iterator it_action=chain_it_vector.begin();it_action!=chain_it_vector.end()-2;it_action++)
            {
                if((*it_action)->m_2nd_position==(*(it_action+1))->m_1st_position&&(*it_action)->m_2nd_position!=65535)
                {
                    result_offset+=4;
                }
            }
            if(result_offset>max_offset)
            {
                max_offset=result_offset;
                C_position::do_action_chain.clear();
                for(vector<vector<C_action_chain>::const_iterator>::iterator it_action=chain_it_vector.begin();it_action!=chain_it_vector.end()-1;it_action++)
                {
                    C_position::do_action_chain.push_back(**it_action);
                }
            }
        }
        else
        {
            flag_add=false;
        }


        chain_it_vector[0]++;
        for(vector<vector<C_action_chain>::const_iterator>::iterator it=chain_it_vector.begin();it!=chain_it_vector.end();it++)
        {
            if(*it==para_vector.end())
            {
                *it=para_vector.begin();
                *(it+1)+=1;
            }
        }
    }
     return result;
 }

 int TeamName::mission_chain(ObjectList& objlist,taskList& tasklist)
 {
     for(vector<C_action_chain>::iterator it=C_position::do_action_chain.begin();it!=C_position::do_action_chain.end();it++)
     {
         switch(it->m_action_num)
        {
            case 1:
                //give(human,obj1)
                //cGive(objlist,tasklist,mytask);
                cPutOn(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,true);
                door_event(objlist,tasklist);
                break;
            case 2:
                //puton(small,big)
                //cPutOn(objlist,tasklist,mytask);
                cPutOn(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,true);
                door_event(objlist,tasklist);
                break;
            case 3:
                //goto(obj)
                //cGoto(objlist,tasklist,mytask);
                cGoto(objlist,tasklist,it->m_1st_obj_num,true);
                break;
            case 4:
                //putdown(obj)
                //cPutDown(objlist,tasklist,mytask);
                cPutDown(objlist,tasklist,it->m_1st_obj_num,true);
                door_event(objlist,tasklist);
                break;
            case 5:
                //pickup(obj)
                //cPickUp(objlist,tasklist,mytask);
                cPickUp(objlist,tasklist,it->m_1st_obj_num,true);
                break;
            case 6:
                //open(obj)
                //cOpen(objlist,tasklist,mytask);
                cOpen(objlist,tasklist,it->m_1st_obj_num,true);
                break;
            case 7:
                //putin(id,continer)
                //cPutIn(objlist,tasklist,mytask);
                cPutIn(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,true);
                door_event(objlist,tasklist);
                break;
            case 8:
                //close(obj)
                //cClose(objlist,tasklist,mytask);
                cClose(objlist,tasklist,it->m_1st_obj_num,true);
                break;
            case 9:
                //takeout(id,continer)
                //cTakeOut(objlist,tasklist,mytask);
                cTakeOut(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,true);
                door_event(objlist,tasklist);
                break;
            default:
                if(debug)
                    cout<<"task error"<<endl;
                break;
        }
        it->done=1;
     }


     return 0;
 }


int TeamName::door_event(ObjectList& objlist,taskList& tasklist)
{

    int is_done=0;
    bool flag_find=false;
    unsigned int obj_id=65535;
    unsigned int action=65535;
    for(vector<vector<C_action_chain> >::iterator it_action_vector=C_position::task_array_door.begin();it_action_vector!=C_position::task_array_door.end();it_action_vector++)
    {
        action=65535;
        if(     (*it_action_vector)[0].m_action_num !=6 && (*it_action_vector)[0].m_action_num !=8   )
        {
            continue;
        }
        action= (*it_action_vector)[0].m_action_num;

        for(vector<C_action_chain>::iterator it_action=it_action_vector->begin();it_action!=it_action_vector->end();it_action++    )
        {
            obj_id=65535;

            if(it_action->done==1)
                break;


            if(objlist.bot.loc==it_action->m_1st_position)
            {
                obj_id=it_action->m_1st_obj_num;
                break;
            }

            if(obj_id==65535&&objlist.bot.loc==objlist.bot.senseLoc)
            {
                flag_find=false;
                for(vector<unsigned int>::iterator it_here=objlist.bot.here.begin();it_here!=objlist.bot.here.end();it_here++)
                {
                    if(it_action->m_1st_obj_num==(*it_here)  )
                    {
                        flag_find=true;
                        obj_id=*it_here;
                        break;
                    }
                }
            }
            if(flag_find==true)
            {
                break;
            }
        }
        if(obj_id!=65535)
        {
            if(action==6)
            {
                //open
                cOpen(objlist,tasklist,obj_id,true);
            }
            else if(action==8)
            {
                //close
                cClose(objlist,tasklist,obj_id,true);
            }

            for(vector<C_action_chain>::iterator it=it_action_vector->begin();it!=it_action_vector->end();it++    )
            {
                it->done=1;
            }

        }

    }
    return 0;
}


 int TeamName::LoadTaskReduce(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector)
 {
     bool continueFlag=false;
     bool continueFlag_2nd=false;
     C_task_reduce* upload_task_reduce;
     Object* obj;
     C_action_chain* p_action_cache=NULL;

     for(vector<myTask>::iterator itTask=tasklist.task.begin();itTask!=tasklist.task.end();itTask++)
     {
         upload_task_reduce=new C_task_reduce();

         upload_task_reduce->m_action_num=itTask->action;

         upload_task_reduce->m_1st_vector.assign(itTask->obj[itTask->firstVar].answer_vectorId.begin()  ,   itTask->obj[itTask->firstVar].answer_vectorId.end()  );
         upload_task_reduce->m_2nd_vector.assign(itTask->obj[itTask->secondVar].answer_vectorId.begin()    ,   itTask->obj[itTask->secondVar].answer_vectorId.end()    );

         task_reduce_para.push_back(*upload_task_reduce);
         delete upload_task_reduce;
     }

     for(vector<C_task_reduce>::iterator it=task_reduce_para.begin();it!=task_reduce_para.end();it++)
     {
         for(vector<unsigned int>::iterator itFirst=it->m_1st_vector.begin();itFirst!=it->m_1st_vector.end();itFirst++)
         {
            continueFlag=false;

            Object& obj=getObj_id(objlist,tasklist,*itFirst);
            if(obj!=*Object::NULLObj)
            {
                if(obj.NO==1||obj.is_locked==true)
                {
                    continueFlag=true;
                    //debug3
                }

            }
            else
            {
                continueFlag=true;
            }

            if(true==continueFlag)
            {
                continue;
            }
            //check debug
            for(vector<unsigned int>::iterator itSecond=it->m_2nd_vector.begin();itSecond!=it->m_2nd_vector.end();itSecond++)
            {
                continueFlag_2nd=false;
                for(vector<struct no_task>::iterator itNoTask=obj.no_action.begin();itNoTask!=obj.no_action.end();itNoTask++)
                {
                    //debug3
                    if(itNoTask->action==it->m_action_num&&itNoTask->actionId==*itSecond)
                    {
                        continueFlag_2nd=true;
                    }
                }

                if(true==continueFlag_2nd)
                {
                    continue;
                }

                p_action_cache=new C_action_chain();

                p_action_cache->num=it->num;
                p_action_cache->m_action_num=it->m_action_num;
                p_action_cache->m_1st_obj_num=*itFirst;
                p_action_cache->m_2nd_obj_num=*itSecond;
                p_action_cache->m_1st_position=getObjLoc_id(objlist,tasklist,*itFirst,0);
                p_action_cache->m_2nd_position=getObjLoc_id(objlist,tasklist,*itSecond,0);

                it->m_optional_action.push_back(*p_action_cache);
                it->m_2nd_todo_vector.push_back(*itSecond);

                delete p_action_cache;
            }
            if(it->m_2nd_todo_vector.size()!=0)
                it->m_1st_todo_vector.push_back(*itFirst);
         }
     }


    //debug now
     return 0;
 }

int TeamName::MakePlan(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector)
{

    vector<unsigned int > index;
    vector<unsigned int> max_index;
    vector<C_action_chain> action_chain_cache_vector;
    vector<C_action_chain> action_chain_cache2;

    int score=0;
    int max_score=-1000;

     for(unsigned int i=0;i<task_reduce_para.size();i++)
     {
         index.push_back(0);
         max_index.push_back(task_reduce_para[i].m_optional_action.size());
     }
     index.push_back(0);



     while(index[index.size()-1]==0)
     {
         action_chain_cache_vector.clear();
         for(unsigned int i=0;i<max_index.size();i++)
         {
             if(true==task_reduce_para[i].done)
             {
                 continue;
             }
             if(task_reduce_para[i].m_optional_action.size()==0)
             {
                 continue;
             }
             action_chain_cache_vector.push_back(task_reduce_para[i].m_optional_action[ index[ i ] ]);
         }
        score=EstimateScore(objlist,tasklist,task_reduce_para,action_chain_cache_vector,action_chain_cache2);

        if(score>max_score)
        {
            max_score=score;
            target_para_vector=action_chain_cache2;
        }
        //debug now

         index[0]+=1;
         for(unsigned int i=0;i<max_index.size();i++)
         {
             if(index[i]>=max_index[i])
             {
                 index[i+1]+=1;
                 index[i]=0;
             }
         }
         target_para_vector.clear();
     }

    return 0;
}



  int TeamName::EstimateScore(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,const vector<C_action_chain>& para_vector,vector<C_action_chain>& target_para_vector)
 {
     int result=0;
     int result_offset=0;
     int max_offset=0;

     vector<vector<C_action_chain>::const_iterator> chain_it_vector;//存储 遍历的序列
     chain_it_vector.clear();


     vector<C_action_chain> toCalculate_vector;//待评分的动作序列
     //vector<vector<C_action_chain>::const_iterator> counter_vector;
     bool flag_add=false;
     //it_vector.reserve(10);



    for(vector<C_action_chain>::const_iterator it=para_vector.begin();it!=para_vector.end();it++)
    {
        chain_it_vector.push_back(para_vector.begin());
        //debug now
    }

    chain_it_vector.push_back(para_vector.begin());


    chain_it_vector[0]=para_vector.begin();

    cout<<chain_it_vector.size()<<endl;

    while(chain_it_vector[chain_it_vector.size()-1]==para_vector.begin())
    {
        //cout<<"qqqq"<<endl;
        for(vector<vector<C_action_chain>::const_iterator>::iterator it=chain_it_vector.begin();it!=chain_it_vector.end()-1;it++)
        {
            for(vector<vector<C_action_chain>::const_iterator>::iterator it2=it+1;it2!=chain_it_vector.end()-1;it2++)
            {
                if(*it2==*it)
                {
                    flag_add=true;
                    break;
                }
            }
            if(flag_add==true)
            {
                break;
            }
        }

        if(flag_add==false)
        {
            //得到目标
            //debug now
            result_offset=0;
            toCalculate_vector.clear();
            for(vector<vector<C_action_chain>::const_iterator>::iterator it_action=chain_it_vector.begin();it_action!=chain_it_vector.end()-1;it_action++)
            {
                toCalculate_vector.push_back(**it_action);
            }
            result_offset=CalculateScore(objlist,tasklist,task_reduce_para,toCalculate_vector);
            if(result_offset>max_offset)
            {
                max_offset=result_offset;
                target_para_vector.clear();
                target_para_vector=toCalculate_vector;

                //for(vector<vector<C_action_chain>::const_iterator>::iterator it_action=chain_it_vector.begin();it_action!=chain_it_vector.end()-1;it_action++)
                //{
                   // target_para_vector.push_back(**it_action);
                //}
            }
        }
        else
        {
            flag_add=false;
        }


        chain_it_vector[0]++;
        for(vector<vector<C_action_chain>::const_iterator>::iterator it=chain_it_vector.begin();it!=chain_it_vector.end();it++)
        {
            if(*it==para_vector.end())
            {
                *it=para_vector.begin();
                *(it+1)+=1;
            }
        }
    }
     return result;
 }


 int TeamName::CalculateScore(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector)
 {
     int result=0;
     ObjectList objlist_analogy;
     objlist_analogy=objlist;
     bool done=false;
     int gotoNum=0;
     int humanIdx;

     for(vector<C_action_chain>::iterator it=target_para_vector.begin();it!=target_para_vector.end();it++)
     {
         switch(it->m_action_num)
         {
             case 1:
                 //give(human,obj1)
                 result=cGive_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                 break;
             case 2:
                 //puton(small,big)
                 result=cPutOn_analogy(objlist_analogy,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num);
                 break;
             case 3:
                 //goto(obj)
                 result=cGoto_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                 break;
             case 4:
                 //putdown(obj)
                 result=cPutDown_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                break;
             case 5:
                 //pickup(obj)
                 result=cPickUp_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                 break;
             case 6:
                 //open(obj)
                 result=cOpen_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                 break;
             case 7:
                 //putin(id,continer)
                 result=cPutIn_analogy(objlist_analogy,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num);
                 break;
             case 8:
                 //close(obj)
                 result=cClose_analogy(objlist_analogy,tasklist,it->m_1st_obj_num);
                 break;
             case 9:
                 //takeout(id,continer)
                 result=cTakeOut_analogy(objlist_analogy,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num);
                 break;
             default:
                 if(debug)
                     cout<<"task error"<<endl;
                 break;
         }
     }

     for(vector<C_task_reduce>::iterator it=task_reduce_para.begin();it!=task_reduce_para.end();it++)
     {
         done=false;
         switch(it->m_action_num)
         {
             case 1:
                 //give(human,obj1)

                 humanIdx=getObjId_name(objlist_analogy,tasklist,"human");
                 Object* humanObj;
                 humanObj=&getObj_id(objlist_analogy,tasklist,humanIdx);
                 if(humanObj==Object::NULLObj)
                 {
                     break;
                 }
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     Object& obj=getObj_id(objlist_analogy,tasklist,*itFirst);
                     if(obj!=*Object::NULLObj)
                     {
                         if(obj.location==humanObj->location)
                         {
                             done=true;
                             break;
                         }
                     }
                 }
                 break;
             case 2:
                 //puton(small,big)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     for(vector<unsigned int>::iterator itSecond=it->m_2nd_todo_vector.begin();itSecond!=it->m_2nd_todo_vector.end();itSecond++)
                     {
                         Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                         Object& secondObj=getObj_id(objlist_analogy,tasklist,*itSecond);
                         if(firstObj!=*Object::NULLObj&&secondObj!=*Object::NULLObj)
                         {
                             if(firstObj.location==secondObj.location&&firstObj.location!=65535)
                             {
                                 done=true;
                                 break;
                             }
                         }
                     }
                 }
                 break;
             case 3:
                 //goto(obj)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                     if(firstObj!=*Object::NULLObj)
                     {
                         if(firstObj.location==objlist_analogy.bot.loc)
                         {
                             if(0==gotoNum)
                             {
                                 done=true;
                                 gotoNum++;
                                 break;
                             }
                         }
                     }
                 }
                 break;
             case 4:
                 //putdown(obj)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     if(objlist_analogy.bot.hold!=*itFirst&&objlist_analogy.bot.plate!=*itFirst)
                     {
                         done=true;
                         break;
                     }
                 }
                break;
             case 5:
                 //pickup(obj)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     if(objlist_analogy.bot.hold==*itFirst||objlist_analogy.bot.plate==*itFirst)
                     {
                         done=true;
                         break;
                     }
                 }
                 break;
             case 6:
                 //open(obj)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                     if(firstObj!=*Object::NULLObj)
                     {
                         if(1==firstObj.is_open)
                         {
                             done=true;
                             break;
                         }
                     }
                 }
                 break;
             case 7:
                 //putin(id,continer)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     for(vector<unsigned int>::iterator itSecond=it->m_2nd_todo_vector.begin();itSecond!=it->m_2nd_todo_vector.end();itSecond++)
                     {
                         Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                         if(firstObj!=*Object::NULLObj)
                         {
                             if(firstObj.is_inside==*itSecond)
                             {
                                 done=true;
                                 break;
                             }
                         }
                     }
                 }
                 break;
             case 8:
                 //close(obj)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                     if(firstObj!=*Object::NULLObj)
                     {
                         if(2==firstObj.is_open)
                         {
                             done=true;
                             break;
                         }
                     }
                 }
                 break;
             case 9:
                 //takeout(id,continer)
                 for(vector<unsigned int>::iterator itFirst=it->m_1st_todo_vector.begin();itFirst!=it->m_1st_todo_vector.end();itFirst++)
                 {
                     for(vector<unsigned int>::iterator itSecond=it->m_2nd_todo_vector.begin();itSecond!=it->m_2nd_todo_vector.end();itSecond++)
                     {
                         Object& firstObj=getObj_id(objlist_analogy,tasklist,*itFirst);
                         if(firstObj!=*Object::NULLObj)
                         {
                             if(firstObj.is_inside!=*itSecond&&firstObj.is_inside!=65535)
                             {
                                 done=true;
                                 break;
                             }
                         }
                     }
                 }
                 break;
             default:
                 if(debug)
                     cout<<"task error"<<endl;
                 break;
         }
         if(true==done)
         {
             result+=20;
         }
     }


     return result;
 }




 int TeamName::MissionTaskReduce(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector)
 {
     int result=0;
     int human_int=0;
     bool breakFlag=false;
     cout<<target_para_vector.size()<<endl;
     for(vector<C_action_chain>::iterator it=target_para_vector.begin();it!=target_para_vector.end();it++)
     {
         switch(it->m_action_num)
         {
             case 1:
                 //give(human,obj1)
                 human_int=getObjId_name(objlist,tasklist,"human");
                 result=cPutOn(objlist,tasklist,it->m_1st_obj_num,human_int,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 else
                 {
                     getObj_id(objlist,tasklist,it->m_1st_obj_num).is_locked=true;
                 }
                 break;
             case 2:
                 //puton(small,big)
                 result=cPutOn(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 else
                 {
                     getObj_id(objlist,tasklist,it->m_1st_obj_num).is_locked=true;
                 }
                 break;
             case 3:
                 //goto(obj)
                 result=cGoto(objlist,tasklist,it->m_1st_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 break;
             case 4:
                 //putdown(obj)
                 result=cPutDown(objlist,tasklist,it->m_1st_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                break;
             case 5:
                 //pickup(obj)
                 result=cPickUp(objlist,tasklist,it->m_1st_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 break;
             case 6:
                 //open(obj)
                 result=cOpen(objlist,tasklist,it->m_1st_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 else
                 {
                     getObj_id(objlist,tasklist,it->m_1st_obj_num).is_locked=true;
                 }
                 break;
             case 7:
                 //putin(id,continer)
                 result=cPutIn(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 else
                 {
                     getObj_id(objlist,tasklist,it->m_1st_obj_num).is_locked=true;
                 }
                 break;
             case 8:
                 //close(obj)
                 result=cClose(objlist,tasklist,it->m_1st_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 else
                 {
                     getObj_id(objlist,tasklist,it->m_1st_obj_num).is_locked=true;
                 }
                 break;
             case 9:
                 //takeout(id,continer)
                 result=cTakeOut(objlist,tasklist,it->m_1st_obj_num,it->m_2nd_obj_num,0);
                 if(-10==result)
                 {
                     breakFlag=true;
                     MakePlan(objlist,tasklist,task_reduce_para,target_para_vector);
                     MissionTaskReduce(objlist,tasklist,task_reduce_para,target_para_vector);
                 }
                 break;
             default:
                 if(debug)
                     cout<<"task error"<<endl;
                 break;
         }
         if(true==breakFlag)
         {
             break;
         }
         for(vector<C_task_reduce>::iterator itTask=task_reduce_para.begin();itTask!=task_reduce_para.end();itTask++)
         {
             if(itTask->num==it->num)
             {
                 itTask->done=1;
                 it->done=1;
                 break;
             }
         }
     }

     return 0;
 }




 int TeamName::cGive_analogy(ObjectList& objlist,taskList& tasklist,unsigned id)
 {
     int result=0;
     unsigned int bigId=getObjId_name(objlist,tasklist,"human");

     if(getObj_id(objlist,tasklist,id).location==getObj_id(objlist,tasklist,bigId).location)
     {

     }
     else
     {
         result+=cPutOn_analogy(objlist,tasklist,id,bigId);
     }


     return result;
 }

int TeamName::cPutIn_analogy(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId)
 {
     int result=0;
     Object& firstObj=getObj_id(objlist,tasklist,id);
     Object& secondObj=getObj_id(objlist,tasklist,continerId);
     if(firstObj!=*Object::NULLObj&&secondObj!=*Object::NULLObj)
     {
         if(firstObj.is_inside==continerId)
         {

         }
         else
         {
             result+=cPickUp_analogy(objlist,tasklist,id);
             result-=4;
             result-=4;
             firstObj.is_inside=continerId;
             secondObj.inside_id.push_back(id);
         }
     }
     return result;
 }


int TeamName::cPutOn_analogy(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId)
 {
     int result=0;
     Object& firstObj=getObj_id(objlist,tasklist,id);
     Object& secondObj=getObj_id(objlist,tasklist,bigId);
     if(firstObj!=*Object::NULLObj&&secondObj!=*Object::NULLObj)
     {
         if(firstObj.is_on==bigId||firstObj.location==secondObj.location)
         {

         }
         else
         {
             result+=cPickUp_analogy(objlist,tasklist,id);
             result-=4;
             result+=cPutDown_analogy(objlist,tasklist,id);
             firstObj.is_on=bigId;
             secondObj.on_id.push_back(id);
         }
     }
     return result;
 }

int TeamName::cPickUp_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id)
 {
     int result=0;
     if(objlist.bot.hold==id||objlist.bot.plate==id)
     {

     }
     else
     {
         result+=cGoto_analogy(objlist,tasklist,id);
         result-=2;
         objlist.bot.hold=id;
     }
     return result;
 }
int TeamName::cPutDown_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id)
 {
     int result=0;
     if(objlist.bot.hold==id)
     {
         result-=3;
         objlist.bot.hold=0;
     }
     else if(objlist.bot.plate==id)
     {
         result-=6;
         objlist.bot.plate=0;
     }
     return result;
 }
int TeamName::cTakeOut_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId) //continerId为0时 需要保证id不在任何容器中 否则只保证inside(id,continer)不为真
{
     int result=0;
    Object& firstObj=getObj_id(objlist,tasklist,id);
    Object& secondObj=getObj_id(objlist,tasklist,continerId);
    if(firstObj!=*Object::NULLObj&&secondObj!=*Object::NULLObj)
    {
         if(firstObj.is_inside!=continerId)
         {

         }
         else
         {
             result+=cGoto_analogy(objlist,tasklist,id);
             result-=3;
             firstObj.is_inside=0;
             vector<unsigned int>::iterator eraseIt=secondObj.inside_id.end();
             for(vector<unsigned int>::iterator it=secondObj.inside_id.begin();it!=secondObj.inside_id.end();it++)
             {
                 if(*it==id)
                 {
                     eraseIt=it;
                     break;
                 }
             }
             if(eraseIt!=secondObj.inside_id.end())
             {
                 secondObj.inside_id.erase(eraseIt);
             }
         }
    }
     return result;
 }

int TeamName::cOpen_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id)
 {
     int result=0;
     Object& firstObj=getObj_id(objlist,tasklist,id);
     if(firstObj!=*Object::NULLObj)
     {
         if(firstObj.is_open!=1)
         {
             result+=cGoto_analogy(objlist,tasklist,id);
             result-=3;
             firstObj.is_open=1;
         }
     }
     return result;
 }
int TeamName::cClose_analogy(ObjectList& objlist,taskList& tasklist,unsigned int continerId)
 {
     int result=0;
     Object& firstObj=getObj_id(objlist,tasklist,continerId);
     if(firstObj!=*Object::NULLObj)
     {
         if(firstObj.is_open!=2)
         {
             result+=cGoto_analogy(objlist,tasklist,continerId);
             result-=3;
             firstObj.is_open=2;
         }
     }
     return result;
 }
int TeamName::cGoto_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id)
  {
     int result=0;
     unsigned int loc=0;
     loc=getObjLoc_id(objlist,tasklist,id,0);
     Object& holdObj=getObj_id(objlist,tasklist,objlist.bot.hold);
     Object& plateObj=getObj_id(objlist,tasklist,objlist.bot.plate);

     if(true==getObj_id(objlist,tasklist,id).sensed)
     {
         if(loc==objlist.bot.loc&&65535!=loc)
         {

         }
         else
         {
             //Move
             result-=4;
             if(65535==loc)
             {
                 objlist.bot.loc=65534;
                 loc=65534;
                 if(holdObj!=*Object::NULLObj)
                 {
                     holdObj.location=objlist.bot.loc;
                 }
                 if(plateObj!=*Object::NULLObj)
                 {
                     plateObj.location=objlist.bot.loc;
                 }

             }
             else
             {
                 objlist.bot.loc=loc;
                 if(holdObj!=*Object::NULLObj)
                 {
                     holdObj.location=objlist.bot.loc;
                 }
                 if(plateObj!=*Object::NULLObj)
                 {
                     plateObj.location=objlist.bot.loc;
                 }
             }

             result-=1;
         }
     }
     else
     {
         if(loc==objlist.bot.loc&&loc!=65535)
         {
             result-=9;
         }
         else if(65535==loc)
         {
             result-=18;
             objlist.bot.loc=65534;
             loc=65534;

             if(holdObj!=*Object::NULLObj)
            {
                holdObj.location=objlist.bot.loc;
            }
            if(plateObj!=*Object::NULLObj)
            {
                plateObj.location=objlist.bot.loc;
            }
         }
         else
         {
             result-=16;
             objlist.bot.loc=loc;
             if(holdObj!=*Object::NULLObj)
             {
                 holdObj.location=objlist.bot.loc;
             }
             if(plateObj!=*Object::NULLObj)
             {
                 plateObj.location=objlist.bot.loc;
             }
         }
     }
     return result;
 }
 //debug final



/*class step end  */

/*class nature start*/
int nature::strToSen()
{
    int pos;
    string strHandle=info_task;

    while((pos=strHandle.find("."))!=string::npos)
    {
        string temp;
        temp.append(strHandle,0,pos+1);
        temp.insert(0," ");
        temp.insert(temp.find(".")," ");
        sentence.push_back(temp);
        strHandle.erase(0,pos+1);
    }
    return 0;
}

int nature::isInfo(string str)
{
    string::size_type index;
    int result=0;
    int whichPos=-1;
    int isPos=-1;
    if((index=str.find(" which is "))!=string::npos)
    {
        whichPos=index;
        whichPos++;
    }
    if((index=str.find(" is "))!=string::npos)
    {
        isPos=index;
        isPos++;
    }

    while(isPos!=-1)
    {
        if((whichPos!=(isPos-6)||whichPos==-1)&&isPos!=-1)
        {
            result=1;
        }

        str.assign(str,isPos+3,str.size());

        if((index=str.find(" which is "))!=string::npos)
        {
            whichPos=index;
            whichPos++;
        }
        else
            whichPos=-1;

        if((index=str.find(" is "))!=string::npos)
        {
            isPos=index;
            isPos++;
        }
        else
            isPos=-1;

    }


    return result;
}

int nature::strSave()
{
    for(vector<string>::iterator it=sentence.begin();it!=sentence.end();it++)
    {
        if(((it->find("there must be"))!=string::npos)||((it->find("There must be"))!=string::npos))
        {
            notnotInfoS.push_back(*it);
        }
        else if(((it->find("there must not be"))!=string::npos)||((it->find("There must not be"))!=string::npos))
        {
            notInfoS.push_back(*it);
        }
        else if((it->find("must be"))!=string::npos)
        {
            notnotInfoS.push_back(*it);
        }
        else if((it->find("must not be"))!=string::npos)
        {
            notInfoS.push_back(*it);
        }
        else if((it->find("must not"))!=string::npos)
        {
            notInfoS.push_back(*it);
        }
        else if((it->find("must"))!=string::npos)
        {
            notnotInfoS.push_back(*it);
        }
        else if((it->find("Do not"))!=string::npos||((it->find("do not"))!=string::npos))
        {
            notTaskS.push_back(*it);
        }
        else if(isInfo(*it))
        {
            infoS.push_back(*it);
        }
        else
        {
            taskS.push_back(*it);
        }
        /*
        else
        {
            taskOrInfoS.push_back(*it);
        }
        */

    }
    return 0;
}

int nature::taskHandler(vector<string>& str,vector<taskStr>& target)
{
    class taskStr* taskItem;
    for(vector<string>::iterator it=str.begin();it!=str.end();it++)
    {
        if(((it->find(" Go to "))!=string::npos)||((it->find(" go to "))!=string::npos)||((it->find(" go "))!=string::npos)||((it->find(" Go "))!=string::npos)||((it->find(" goto "))!=string::npos)||((it->find(" Goto "))!=string::npos))
        {
            int pos=0;
            taskItem=new taskStr();
            taskItem->action="goto";
            pos=it->find(" to ");
            pos++;
            taskItem->objA.append(*it,pos+3,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if(((it->find("pickup"))!=string::npos)||((it->find("Pickup"))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" pickup ");
            pos++;
            pos+=4;
            pos1=pos;
            pos1=pos1+3;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="pickup";
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="pickup";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if(((it->find("pick up"))!=string::npos)||((it->find("Pick up"))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" up ");
            pos++;
            pos1=pos;
            pos1=pos1+3;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="pickup";
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="pickup";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if(((it->find(" take out "))!=string::npos)||((it->find(" Take out "))!=string::npos))
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;

            pos=it->find(" out ");
            pos++;
            posB=it->find(" from ");
            posB++;
            pos1=pos;
            pos1=pos1+4;
            pos2=pos1;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="takeout";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,pos1-pos2);
                taskItem->objB.append(*it,posB+5,it->size());
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="takeout";
            //taskItem->objA.append(*it,pos+4,posB-pos-4);
            taskItem->objA.append(*it,pos2,posB-pos2);
            taskItem->objB.append(*it,posB+5,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if(((it->find(" take "))!=string::npos)||((it->find(" Take "))!=string::npos))
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;

            if((pos=it->find(" take "))==string::npos)
            {
                pos=it->find(" Take ");
            }
            pos++;
            posB=it->find(" out of ");
            posB++;
            pos1=pos;
            pos1=pos1+5;
            pos2=pos1;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="takeout";
                taskItem->objA.append(*it,pos2,pos1-pos2);
                taskItem->objB.append(*it,posB+7,it->size());
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="takeout";
            taskItem->objA.append(*it,pos2,posB-pos2);
            taskItem->objB.append(*it,posB+7,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" open the door of "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" open the door of ");
            pos++;
            pos1=pos;
            pos1=pos1+17;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="open";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="open";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" Open the door of "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" Open the door of ");
            pos++;
            pos1=pos;
            pos1=pos1+17;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="open";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="open";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" open "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" open ");
            pos++;
            pos1=pos;
            pos1=pos1+5;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="open";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="open";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" Open "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" Open ");
            pos++;
            pos1=pos;
            pos1=pos1+5;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="open";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="open";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" close the door of "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" close the door of ");
            pos++;
            pos1=pos;
            pos1=pos1+18;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="close";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="close";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" Close the door of "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" Close the door of ");
            pos++;
            pos1=pos;
            pos1=pos1+18;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="close";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="close";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" close "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" close ");
            pos++;
            pos1=pos;
            pos1=pos1+6;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="close";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="close";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" Close "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" Close ");
            pos++;
            pos1=pos;
            pos1=pos1+6;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="close";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="close";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" put "))!=string::npos)
        {
            if((it->find(" on "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" on ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+3,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+3,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" near "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" near ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+5,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+5,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" next to "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" next to ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+7,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+7,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" down to "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" down to ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+7,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+7,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" put down "))!=string::npos)
            {
                int pos=0;
                int pos1=0;
                int pos2=0;
                pos=it->find(" put down ");
                pos++;
                pos1=pos;
                pos1=pos1+9;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putdown";
                    //taskItem->objA.append(*it,pos+17,it->size());
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putdown";
                taskItem->objA.append(*it,pos2,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" down "))!=string::npos)
            {

                int pos=0;
                int pos1=0;
                int pos2=0;
                pos=it->find(" put ");
                pos++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putdown";
                    //taskItem->objA.append(*it,pos+17,it->size());
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putdown";
                taskItem->objA.append(*it,pos2,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" in "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" in ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putin";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+3,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putin";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+3,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" into "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" into ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putin";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+5,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putin";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+5,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            *it="";
        }
        else if((it->find(" Put "))!=string::npos)
        {
            if((it->find(" on "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" Put ");
                pos++;
                posB=it->find(" on ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+3,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+3,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" near "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" near ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+5,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+5,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" next to "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" next to ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+7,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+7,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" down to "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" down to ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="puton";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+7,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="puton";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+7,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" Put down "))!=string::npos)
            {
                int pos=0;
                int pos1=0;
                int pos2=0;
                pos=it->find(" Put down ");
                pos++;
                pos1=pos;
                pos1=pos1+9;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putdown";
                    //taskItem->objA.append(*it,pos+17,it->size());
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putdown";
                taskItem->objA.append(*it,pos2,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" down "))!=string::npos)
            {
                int pos=0;
                int pos1=0;
                int pos2=0;
                pos=it->find(" put ");
                pos++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putdown";
                    //taskItem->objA.append(*it,pos+17,it->size());
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putdown";
                taskItem->objA.append(*it,pos2,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" in "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" in ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putin";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+3,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putin";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+3,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            else if((it->find(" into "))!=string::npos)
            {
                int pos=0;
                int posB=0;
                int pos1=0;
                int pos2=0;

                pos=it->find(" put ");
                pos++;
                posB=it->find(" into ");
                posB++;
                pos1=pos;
                pos1=pos1+4;
                pos2=pos;
                while((pos1=it->find(" and ",pos1))!=string::npos)
                {
                    pos1++;
                    taskItem=new taskStr();
                    taskItem->action="putin";
                    //taskItem->objA.append(*it,pos+4,posB-pos-4);
                    taskItem->objA.append(*it,pos2,pos1-pos2);
                    taskItem->objB.append(*it,posB+5,it->size());
                    target.push_back(*taskItem);
                    delete taskItem;
                    pos2=pos1+4;
                    pos1=pos2;
                }
                taskItem=new taskStr();
                taskItem->action="putin";
                //taskItem->objA.append(*it,pos+4,posB-pos-4);
                taskItem->objA.append(*it,pos2,posB-pos2);
                taskItem->objB.append(*it,posB+5,it->size());
                target.push_back(*taskItem);
                delete taskItem;
            }
            *it="";
        }
        else if((it->find(" Give "))!=string::npos)
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" Give ");
            pos++;
            pos1=pos;
            pos1=pos1+5;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="give";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);

                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="give";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
        else if((it->find(" give "))!=string::npos)
        {

            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" give ");
            pos++;
            pos1=pos;
            pos1=pos1+5;
            pos2=pos;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                taskItem=new taskStr();
                taskItem->action="give";
                //taskItem->objA.append(*it,pos+17,it->size());
                taskItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*taskItem);
                delete taskItem;
                pos2=pos1+4;
                pos1=pos2;
            }
            taskItem=new taskStr();
            taskItem->action="give";
            taskItem->objA.append(*it,pos2,it->size());
            target.push_back(*taskItem);
            delete taskItem;
            *it="";
        }
    }
    return 0;
}

int nature::infoHandler(vector<string>& str,vector<infoStr>& target)
{
    class infoStr* infoItem;
    for(vector<string>::iterator it=str.begin();it!=str.end();it++)
    {
        if(    ((it->find(" plate "))!=string::npos)    ||((it->find(" Plate "))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" plate ");
            if(pos==string::npos)
                pos=it->find(" Plate ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="plate";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="plate";
            infoItem->objA.append(*it,pos2,pos-pos2);
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if(    ((it->find(" hold "))!=string::npos)    ||((it->find(" hold "))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" hold ");
            if(pos==string::npos)
                pos=it->find(" hold ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="hold";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="hold";
            infoItem->objA.append(*it,pos2,pos-pos2);
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if((it->find(" on "))!=string::npos)
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" on ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="on";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                infoItem->objB.append(*it,pos+3,it->size());
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="on";
            infoItem->objA.append(*it,pos2,pos-pos2);
            infoItem->objB.append(*it,pos+3,it->size());
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if((it->find(" near "))!=string::npos)
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" near ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="on";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                infoItem->objB.append(*it,pos+5,it->size());
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="on";
            infoItem->objA.append(*it,pos2,pos-pos2);
            infoItem->objB.append(*it,pos+5,it->size());
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if((it->find(" next to "))!=string::npos)
        {

            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" next to ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="on";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                infoItem->objB.append(*it,pos+8,it->size());
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="on";
            infoItem->objA.append(*it,pos2,pos-pos2);
            infoItem->objB.append(*it,pos+8,it->size());
            target.push_back(*infoItem);
            delete infoItem;

        }
        else if((it->find(" in "))!=string::npos)
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" in ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="inside";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                infoItem->objB.append(*it,pos+3,it->size());
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="inside";
            infoItem->objA.append(*it,pos2,pos-pos2);
            infoItem->objB.append(*it,pos+3,it->size());
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if(    ((it->find(" open "))!=string::npos)    ||((it->find(" opened "))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" open ");
            if(pos==string::npos)
                pos=it->find(" opened ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                if((it->find(" not open"))!=string::npos)
                    infoItem->prep="closed";
                else
                    infoItem->prep="opened";

                infoItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            if((it->find(" not open"))!=string::npos)
                    infoItem->prep="closed";
                else
                    infoItem->prep="opened";
            infoItem->objA.append(*it,pos2,pos-pos2);
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if(    ((it->find(" close "))!=string::npos)    ||((it->find(" closed "))!=string::npos))
        {
            int pos=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" close ");
            if(pos==string::npos)
                pos=it->find(" closed ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                if((it->find(" not close"))!=string::npos)
                    infoItem->prep="opened";
                else
                    infoItem->prep="closed";

                infoItem->objA.append(*it,pos2,pos1-pos2);
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            if((it->find(" not close"))!=string::npos)
                    infoItem->prep="opened";
                else
                    infoItem->prep="closed";
            infoItem->objA.append(*it,pos2,pos-pos2);
            target.push_back(*infoItem);
            delete infoItem;
        }
        else if((it->find(" inside "))!=string::npos)
        {
            int pos=0;
            int posB=0;
            int pos1=0;
            int pos2=0;
            pos=it->find(" in ");
            pos++;
            while((pos1=it->find(" and ",pos1))!=string::npos)
            {
                pos1++;
                infoItem=new infoStr();
                infoItem->prep="inside";
                infoItem->objA.append(*it,pos2,pos1-pos2);
                infoItem->objB.append(*it,pos+3,it->size());
                target.push_back(*infoItem);
                delete infoItem;
                pos1=pos1+4;
                pos2=pos1;
            }
            infoItem=new infoStr();
            infoItem->prep="inside";
            infoItem->objA.append(*it,pos2,pos-pos2);
            infoItem->objB.append(*it,pos+7,it->size());
            target.push_back(*infoItem);
            delete infoItem;
        }

    }
    return 0;
}


int nature::objStr(string& get,string& target,string var)
{
    //debug human
    /*
    if(get.find("human")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("human");
        target.append(")");
    }
    */
    if(get.find("plant")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("plant");
        target.append(")");
    }
    else if(get.find("couch")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("couch");
        target.append(")");
    }
    else if(get.find("chair")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("chair");
        target.append(")");
    }
    else if(get.find("sofa")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("sofa");
        target.append(")");
    }
    else if(get.find("bed")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("bed");
        target.append(")");
    }
    else if(get.find("worktable")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("worktable");
        target.append(")");
    }
    else if(get.find("workspace")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("workspace");
        target.append(")");
    }
    else if(get.find("table")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("table");
        target.append(")");
    }
    else if(get.find("teapoy")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("teapoy");
        target.append(")");
    }
    else if(get.find("desk")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("desk");
        target.append(")");
    }
    else if(get.find("television")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("television");
        target.append(")");
    }
    else if(get.find("airconditioner")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("airconditioner");
        target.append(")");
    }
    else if(get.find("washmachine")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("washmachine");
        target.append(")");
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }
    else if(get.find("closet")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("closet");
        target.append(")");
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }
    else if(get.find("cupboard")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("cupboard");
        target.append(")");
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }
    else if(get.find("refrigerator")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("refrigerator");
        target.append(")");
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }
    else if(get.find("microwave")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("microwave");
        target.append(")");
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }
    else if(get.find("book")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("book");
        target.append(")");
    }
    else if(get.find("can")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("can");
        target.append(")");
    }
    else if(get.find("remotecontrol")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("remotecontrol");
        target.append(")");
    }
    else if(get.find("bottle")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("bottle");
        target.append(")");
    }
    else if(get.find("cup")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("cup");
        target.append(")");
    }
    else if(get.find("human")!=string::npos)
    {
        target.append(" (sort ");
        target.append(var);
        target.append(" ");
        target.append("human");
        target.append(")");
    }

    if(get.find("white")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("white");
        target.append(")");
    }
    else if(get.find("red")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("red");
        target.append(")");
    }
    else if(get.find("green")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("green");
        target.append(")");
    }
    else if(get.find("yellow")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("yellow");
        target.append(")");
    }
    else if(get.find("blue")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("blue");
        target.append(")");
    }
    else if(get.find("black")!=string::npos)
    {
        target.append(" (color ");
        target.append(var);
        target.append(" ");
        target.append("black");
        target.append(")");
    }

    if(get.find("big")!=string::npos)
    {
        target.append(" (size ");
        target.append(var);
        target.append(" ");
        target.append("big");
        target.append(")");
    }
    else if(get.find("small")!=string::npos)
    {
        target.append(" (size ");
        target.append(var);
        target.append(" ");
        target.append("small");
        target.append(")");
    }


    if(get.find("container")!=string::npos)
    {
        target.append(" (type ");
        target.append(var);
        target.append(" ");
        target.append("container");
        target.append(")");
    }

    return 0;
}


int nature::cTask(string st,vector<taskStr>& get,string& str,string ed)
{
    if(str=="give")
    {
        str="give human";
    }
    for(vector<taskStr>::iterator it=get.begin();it!=get.end();it++)
    {
        if(it->action=="give")
        {
            it->action="give human";
        }
        str.append(st);
        str.append("(:task (");
        str.append(it->action);
        if((it->action=="putin")||(it->action=="puton")||(it->action=="takeout"))
        {
            str.append(" X Y)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            objStr(it->objB,str,"Y");
            str.append(")");
        }
        else
        {
            str.append(" X)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            str.append(")");
        }
        str.append(")");

        str.append(ed);
    }
    return 0;
}

int nature::cInfo(string st,vector<infoStr>& get,string& str,string ed)
{
    for(vector<infoStr>::iterator it=get.begin();it!=get.end();it++)
    {
        str.append(st);
        str.append("(:info (");
        str.append(it->prep);
        if((it->prep=="on"))
        {
            str.append(" X Y)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            objStr(it->objB,str,"Y");
            str.append(")");
        }
        else if((it->prep=="inside"))
        {
            str.append(" X Y)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            objStr(it->objB,str,"Y");
            str.append(")");
        }
        else if((it->prep=="opened"))
        {
            str.append(" X)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            str.append(")");
        }
        else if((it->prep=="closed"))
        {
            str.append(" X)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            str.append(")");
        }
        else if((it->prep=="plate"))
        {
            str.append(" X)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            str.append(")");
        }
        else if((it->prep=="hold"))
        {
            str.append(" X)");
            str.append(" (:cond ");
            objStr(it->objA,str,"X");
            str.append(")");
        }
        str.append(ed);
    }
    return 0;
}
int nature::saveTovector()
{
    taskHandler(taskS,task);
    infoHandler(infoS,info);
    taskHandler(notTaskS,notTask);
    infoHandler(notInfoS,notInfo);
    infoHandler(notnotInfoS,notnotInfo);
    return 0;
}
int nature::converToIns(string nat)
{
    const string consnot="(:cons_not ";
    const string consnotnot="(:cons_notnot ";
    const string ed=")";
    info_task=nat;
    strToSen();
    strSave();
    saveTovector();

    result.append("(:ins ");

    cTask("",task,result,"");
    cInfo("",info,result,"");
    cTask(consnot,notTask,result,ed);
    cInfo(consnot,notInfo,result,ed);
    cInfo(consnotnot,notnotInfo,result,ed);

    result.append(")");
    if(debug)
        cout<<result<<endl;
    return 0;
}
/*class nature end  */
#endif // HTEAM_INCLUDED
//task需要修改 firstVar he secondVar
