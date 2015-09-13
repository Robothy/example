#ifndef TEAM_INCLUDED
#define TEAM_INCLUDED
//#include"/home/dell/mytools/cpptest/robocup/HTeam.hpp"
#include<string>
#include<iostream>
#include<cctype>
#include<algorithm>
//#include"cserver/plug.hpp"


#include"/home/robo/myzone/robocup/Planner-release-2.07-src-bisai/include/cserver/plug.hpp"

#include"boost/regex.hpp"

#define RESERVE_NUM 30
#define IS_RESERVE false

using namespace std;
using namespace _home;
using std::vector;
namespace myplan
{
    class C_para_2
    {
    public:
        unsigned int x;
        unsigned int y;
        C_para_2()
        {
            x=65535;
            y=65535;
        }
    };

    class taskStr
    {
    public:
        string action;
        string objA;
        string objB;
    };
    class infoStr
    {
    public:
        string prep;
        string objA;
        string objB;
    };
    class nature
    {
    public:
        string info_task;
        string result;
        vector<string> sentence;
        int strToSen();
        int strSave();
        int saveTovector();
        int taskHandler(vector<string>& str,vector<taskStr>& target);
        int infoHandler(vector<string>& str,vector<infoStr>& target);
        int cTask(string st,vector<taskStr>& get,string& str,string ed);
        int cInfo(string st,vector<infoStr>& get,string& str,string ed);
        int objStr(string& get,string& target,string var);
        int converToIns(string nat);
        int isInfo(string str);
        void d_ebug()
        {
            cout<<notnotInfoS[0]<<endl;
        }
    private:
        vector<taskStr> task;
        vector<infoStr> info;
        vector<taskStr> notTask;
        vector<infoStr> notInfo;
        vector<infoStr> notnotInfo;

        vector<string> taskOrInfoS;
        vector<string> taskS;
        vector<string> infoS;
        vector<string> notTaskS;
        vector<string> notInfoS;
        vector<string> notnotInfoS;
    };
    class askInformation
    {
    public:
        static vector<string> box;
    };
    vector<string> askInformation::box;

    class function
    {
    public:
        unsigned int ColorToInt(string str);
        unsigned int SizeToInt(string str);
        unsigned int DoorToInt(string str);
    };

    class Robot
    {
    public:
        unsigned int loc;
        unsigned int plate;
        unsigned int hold;
        vector<unsigned int> here;
        vector<unsigned int> not_go;
        unsigned int senseLoc;

        string loc_str;
        string plate_str;
        string hold_str;

        vector<unsigned int>answer_loc;
        vector<unsigned int>answer_plate;
        vector<unsigned int>answer_hold;
        Robot()
        {
            loc=65535;
            plate=65535;
            hold=65535;
            senseLoc=65535;
            loc_str=string("");
            plate_str=string("");
            hold_str=string("");
        }
    };

    struct no_task
    {
        unsigned int action;//不允许执行的动作
        unsigned int actionId;//no_action对应动作的参数
        no_task()
        {
            action=65535;
            actionId=65535;
        }
    };

    class Object
    {
    public:
        static Object* NULLObj;

        unsigned int m_match;
        string id_str;
        unsigned int id; //物体编号，对应数组下标
        unsigned int answer_id;
        vector<unsigned int> answer_vectorId;

        string name,type; //物体名称///////////////////////////////////////////////////////////////

        unsigned int location; //物体位置
        string location_str;

        vector<unsigned int> near;//
        vector<string> near_str;

        unsigned int color; //物体颜色：0：无，1：white,2:red,3:green,4:yellow,5:blue,6:black

        unsigned int size; //表示物体的大小，1为小物体small，2为大物体big

        unsigned int is_inside; //小物体的属性，小物体是否在大物体里面，0表示否,其他对应值表示在对应id的物体上
        string is_inside_str;

        unsigned int is_on; //小物体是否在大物体上面，0表示否,其他对应值表示在对应id的物体上
        string is_on_str;

        vector<unsigned int> on_id; //大物体上面的小物体，对应小物体的id
        vector<string> on_id_str;

        unsigned int index;//大物体上面小物体的个数//////////////////////////////////////////////////////////////

        vector<unsigned int> inside_id;//大物体的属性，大物体里面的小物体，值对应小物体的id
        vector<string> inside_id_str;

        unsigned int is_open; //1表示门是开的，2表示门是关的

        unsigned int NO;//1表示禁止被操作，0表示可以被操作
        unsigned int action_flag; //1表示被操作，0表示未被操作过
        unsigned int not_info_flag; //1表在约束not info中涉及，0表示未涉及
        unsigned int not_task_flag; //1表在约束中not task中涉及，0表示未涉及
        bool is_locked;//物体是否允许被操作 （执行完任务后锁定，默认不锁定）
        unsigned int hold_locked;//物体是否允许被放下 默认为0：不知道  1：不允许放下  2:不允许拿起 3：随意
        unsigned int hold_flag;//物体是否需要保持拿着 默认为0：不需要 1：需要 PS：这项的优先级小于hold_locked
        bool is_asked;//物体是否被询问过 true为 询问过
        int need_plate;//物体是否需要保持在盘中默认为0 1：应该保持盘中  2：应该保持不在盘中
        vector<unsigned int> no_at;
        int keep_door;//容器是否允许被打开或者关闭 默认为0 1不允许
        int give_up;//允许到物体位置去 默认为0 1为不允许
        int need_hold;//默认为0 1需要拿着 2随意 3要放下
        bool sensed;//true表示被sense到过
        vector<struct no_task> no_action;

        bool operator ==(const Object& s)
        {
            if(this==&s)
                return true;
            else
                return false;
        }

        bool operator !=(const Object& s)
        {
            if(this==&s)
                return false;
            else
                return true;
        }

        Object()
        {
            m_match=65535;
            id_str=string("");
            id=65535; // 物体编号，对应数组下标
            answer_id=65535;

            name=string("");
            type=string(""); //物体名称///////////////////////////////////////////////////////////////

            location=65535; //物体位置
            location_str=string("");

            //near=65535;//
            //near_str=string("");

            color=65535; //物体颜色：0：无，1：white,2:red,3:green,4:yellow,5:blue,6:black

            size=65535; //表示物体的大小，1为小物体small，2为大物体big

            is_inside=65535; //小物体的属性，小物体是否在大物体里面，0表示否,其他对应值表示在对应id的物体上
            is_inside_str=string("");

            is_on=65535; //小物体是否在大物体上面，0表示否,其他对应值表示在对应id的物体上
            is_on_str=string("");

            //vector<unsigned int> on_id; //大物体上面的小物体，对应小物体的id
            //vector<string> on_id_str;

            index=65535;//大物体上面小物体的个数//////////////////////////////////////////////////////////////

            //vector<unsigned int> inside_id; //大物体的属性，大物体里面的小物体，值对应小物体的id
            //vector<string> inside_id_str;

            is_open=65535; //1表示门是开的，2表示门是关的

            NO=65535;//1表示禁止被操作，0表示可以被操作
            action_flag=65535; //1表示被操作，0表示未被操作过
            not_info_flag=65535; //1表在约束not info中涉及，0表示未涉及
            not_task_flag=65535; //1表在约束中not task中涉及，0表示未涉及
            is_locked=false;//物体是否允许被操作 （执行完任务后锁定，默认不锁定）
            hold_locked=0;//物体是否允许被放下 默认为0：不知道  1：不允许放下  2:不允许拿起 3：随意
            need_hold=0;
            hold_flag=0;//物体是否需要保持拿着 默认为0：不需要 1：需要 PS：这项的优先级小于hold_locked
            is_asked=false;
            need_plate=0;
            keep_door=0;
            give_up=0;
            sensed=false;
        };

        bool compare(Object& obj);

    };
    Object* Object::NULLObj=new Object();
    //NULLObj=new Object();


    class stringHandler
    {
        public:
            string cons_notnot();
            string cons_not();
            string info();
            string task();
            string cond(string str);
            string info(string str);
            string task(string str);
            void GetIns(string ins);
        private:
            string insString;
        protected:
    };

    class ObjectList:public function
    {
    public:
        vector<Object> obj;
        vector<unsigned int> m_big_obj_id_vector;
        Robot bot;
        void EnvHandler(string Env);
        unsigned int m_big_obj_number;

        Object& operator[](string str)
        {
            m_big_obj_number=0;
            bool find_flag=false;
            for(vector<Object>::iterator it=obj.begin();it!=obj.end();it++)
            {
                if(it->id_str==str)
                    return *it;
            }
            return *Object::NULLObj;
        }
    protected:
    private:
        string getTempString(string regIt);
    };
    class myTask:public function
    {
    public:
        unsigned int action;  //具体任务所对应的编号，1：give(human,obj1),2:puton(obj1,obj2),3:goto(obj),4:putdown(obj),
	//                              5:pickup(obj),6:open(obj),7:putin(obj1,obj2),8:close(obj),9takeout(obj1,obj2) 10.放在盘子中
        string firstVar;
        string secondVar;
        ObjectList obj;

        unsigned int m_first;
        unsigned int m_second;
        vector<C_para_2> m_answer_vector;
        vector<C_para_2> m_answer_vector_backup;

        unsigned int m_first_match;//第一个变量需要符合条件的数量
        unsigned int m_second_match;//第二个变量需要符合条件的数量

        bool is_done;//标记任务是否已经完成
        bool is_doing;//标记任务是否正在完成
        bool is_ignored;//标记任务是否被忽略
        int ActionToInt(string actionStr);

        int priority;
        bool operator < (const myTask& item) const
        {
            return priority<item.priority;
        }


        myTask()
        {
            m_first=65535;
            m_second=65535;
            firstVar="";
            secondVar="";
            priority=-1;
            is_done=false;
            is_doing=false;
            is_ignored=false;
        }
    private:
    protected:
    };
    class taskList:public function
    {
    public:
        vector<myTask> task;
        vector<myTask> task_done;
        vector<myTask> task_forgo;
        vector<myTask> cons_notTask;

        vector<ObjectList> info;
        vector<ObjectList> cons_notInfo;
        vector<ObjectList> cons_notnotInfo;
        void TaskHandler(string Task);

        int BackUp()
        {
            for(vector<myTask>::iterator it=task.begin();it!=task.end();it++)
            {
                it->m_answer_vector_backup.assign(it->m_answer_vector.begin(),it->m_answer_vector.end());
            }
            return 0;
        }

    private:

        void getInfo(vector<string>& sCons_infoList);
        void getTask(vector<string>& sCons_taskList);
        void getCons_notInfo(vector<string>& sCons_notInfo);
        void getCons_notnotInfo(vector<string>& sCons_notnotList);
        void getCons_notTask(vector<string>& sCons_notTask);
    };


    class taskBox
    {
    public:

    };

    class C_action_chain
    {
    public:
        int num;
        unsigned int m_action_num;
        unsigned int m_1st_position;
        unsigned int m_2nd_position;
        unsigned int m_1st_obj_num;
        unsigned int m_2nd_obj_num;//针对putin takeout这些动作
        int done;//0表示未完成1表示已完成
        C_action_chain()
        {
            done =0;
            num=-1;
            m_action_num=65535;
            m_1st_position=65535;
            m_2nd_position=65535;
            m_1st_obj_num=65535;
            m_2nd_obj_num=65535;//针对putin takeout这些动作
        }
    };
     class C_task_reduce:public C_action_chain
     {
     public:
         static int counter;

         vector<unsigned int> m_1st_vector;
         vector<unsigned int> m_2nd_vector;

         vector<unsigned int> m_1st_todo_vector;
         vector<unsigned int> m_2nd_todo_vector;

         vector<C_action_chain> m_optional_action;

         unsigned int done_1st;
         unsigned int done_2nd;
         C_task_reduce()
         {
             num=counter;
             counter++;
             done_1st=65535;
             done_2nd=65535;
         }
     };
     int C_task_reduce::counter=0;

    class C_grap
    {
    public:
        unsigned int m_position;
        unsigned int m_visited;
        C_grap()
        {
            m_position=65535;
            m_visited=0;
        }
    };

    class C_position
    {
    public:
        unsigned int m_num;
        vector<Object> m_obj_vector;
        vector<C_action_chain*> m_p_action_chain_zero_vector;
        vector<C_action_chain*> m_p_action_chain_end_vector;
        static vector<C_action_chain> action_chain;
        static vector<C_action_chain> do_action_chain;
        static vector<vector<C_action_chain> > task_array_door;
        static vector<vector<C_action_chain> > task_array;
        C_position()
        {
            m_num=65535;
        }
    };
    vector<C_action_chain> C_position::action_chain;
    vector<C_action_chain> C_position::do_action_chain;
    vector<vector<C_action_chain> > C_position::task_array_door;
    vector<vector<C_action_chain> > C_position::task_array;

    class C_map
    {
    public:
        vector<C_position> m_position_vector;
    };






}





namespace _home
{
    using namespace myplan;
    void toLower(string& str)
    {
        for(int i=0;i<str.length();i++)
            str[i]=tolower(str[i]);
    }
    class TeamName:public Plug
    {
    public:
        TeamName();

        C_map m_map;





        int mission(ObjectList& objlist,taskList& tasklist);
        int letsGo(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int mission_no_res(ObjectList& objlist,taskList& tasklist);
        int letsGo_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int supplyObjectList(ObjectList& objlist,taskList& tasklist);

        unsigned int ChooseObj(ObjectList& objlist,taskList& tasklist,vector<unsigned int> para_vector);
        unsigned int ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,vector<unsigned int> para_vector);

        C_para_2 ChooseObj_big(ObjectList& objlist,taskList& tasklist,vector<C_para_2> para_vector);
        C_para_2 ChooseObj_big_Sense(ObjectList& objlist,taskList& tasklist,vector<C_para_2> para_vector);

        unsigned int ChooseObj(ObjectList& objlist,taskList& tasklist,myTask& para_task);
        unsigned int ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task);

        unsigned int ChooseObj_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<unsigned int> para_vector);

        C_para_2 ChooseObj_big(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<C_para_2> para_vector);
        C_para_2 ChooseObj_big_Sense(ObjectList& objlist,taskList& tasklist,myTask& para_task,vector<C_para_2> para_vector);


        int ChooseObj_ForAll(ObjectList& objlist,taskList& tasklist);
        int supplyTaskList(ObjectList& objlist,taskList& tasklist);

        int InsertTask(ObjectList& objlist,taskList& tasklist);



        int cGive(ObjectList& objlist,taskList& tasklist,myTask& mytask);


        //flag说明：4是res调用的

        int cPutIn(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutIn(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId,int check_flag);

        int cPutOn(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutOn(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId,int check_flag);

        int cPickUp(ObjectList& objlist,taskList& tasklist,myTask& mytask);//working
        int cPickUp(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag);//working

        int cPutDown(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutDown(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag);

        int cTakeOut(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cTakeOut(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId,int check_flag);
        //continerId为0时 需要保证id不在任何容器中 否则只保证inside(id,continer)不为真

        int cOpen(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cOpen(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag);

        int cClose(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cClose(ObjectList& objlist,taskList& tasklist,unsigned int continerId,int check_flag);


        int cGoto(ObjectList& objlist,taskList& tasklist,myTask& mytask);//working2
        int cGoto(ObjectList& objlist,taskList& tasklist,unsigned int id,int check_flag);//flag为true时移动前会检查东西是否可以带过去  working2


        int cGive_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);


        //flag说明：4是res调用的

        int cPutIn_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutIn_no_res(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId);

        int cPutOn_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutOn_no_res(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId);

        int cPickUp_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);//working
        int cPickUp_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id);//working

        int cPutDown_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cPutDown_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id);

        int cTakeOut_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cTakeOut_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId);
        //continerId为0时 需要保证id不在任何容器中 否则只保证inside(id,continer)不为真

        int cOpen_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cOpen_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id);

        int cClose_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);
        int cClose_no_res(ObjectList& objlist,taskList& tasklist,unsigned int continerId);


        int cGoto_no_res(ObjectList& objlist,taskList& tasklist,myTask& mytask);//working2
        int cGoto_no_res(ObjectList& objlist,taskList& tasklist,unsigned int id);//flag为true时移动前会检查东西是否可以带过去  working2


        int eMove(unsigned int loc);
        int ePickUp(unsigned int id);
        int ePutDown(unsigned int id);//do
        int eToPlate(unsigned int id);
        int eFromPlate(unsigned int id);
        int eOpen(unsigned int continerId);
        int eClose(unsigned int continerId);
        int ePutIn(unsigned int objId,unsigned int continerId);
        int eTakeOut(unsigned int objId,unsigned int continerId);
        string eAskLoc(unsigned a);


        void funPriority(taskList& tasklist);


        int eSense(ObjectList& objlist,taskList& tasklist,unsigned int id);//若ID在当前位置返回ID否则返回0
        Object& getObj_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//由ID返回Obj引用
        Object& getObj_Info_idStr(ObjectList& objlist,taskList& tasklist,ObjectList& info,string idStr);//返回在info中为idStr的obj
        Object& getObj_Task_idStr(ObjectList& objlist,taskList& tasklist,myTask& task,string idStr);//返回在task中为idStr的obj
        int getObjId_name(ObjectList& objlist,taskList& tasklist,string sortName);//由Obj名字寻找objId 未找到返回-1

        int answer_info(ObjectList& objlist,taskList& tasklist);//解出X和Y
        int answer_task(ObjectList& objlist,taskList& tasklist);//解出X和Y

        bool can_plate_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//判断id的物品是否可以放在盘子中
        bool can_open_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//判断id的物品是否可以open
        bool can_close_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//判断id的物品是否可以close
        bool can_at_id_loc(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int loc);//判断id的物品是否可以放在loc

        int getObjLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//由ObjId寻找Obj的location 返回location 未找到返回-1
        int getObjLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id,int i_para);//由ObjId寻找Obj的location 返回location 未找到返回-1  此函数不会执行AskLoc
        int askLoc_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//返回id的位置
        int inContiner_id(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId);//判断id的物品是否在容器中 返回容器ID 若不在容器中返回0
        //如果continerId是0 则在任何容器中就返回容器Id 不在任何容器中返回0
        int findObj(ObjectList& objlist,taskList& tasklist,myTask& mytask,int flag);   //返回ObjId 如果未找到合适的返回-1
        bool isIn_info_id(ObjectList& objlist,taskList& tasklist,unsigned int id);//判断id的物品是否涉及info

        int resHandler_nnInfo(ObjectList& objlist,taskList& tasklist,int remain_hold);//对约束处理 remain_hold为true时不改变手中物品
        int resHandler_nnInfo(ObjectList& objlist,taskList& tasklist);
        int resHandler_nTask(ObjectList& objlist,taskList& tasklist);


        //bool resHandler_action(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId);
        //检查动作是否允许执行 若不允许返回false   没有secondIdshi时 则为0

        bool resHandler_nTask(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId);
        //检查动作是否允许执行 若不允许返回false   没有secondIdshi时 则为0

        int resHandler_nInfo(ObjectList& objlist,taskList& tasklist);
        int resHandler_nInfo(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId,int remain_hold);
        int Do_no_res(ObjectList& objlist,taskList& tasklist,unsigned int actionId,unsigned firstId,unsigned int secondId);
        //执行动作 并且不违反notInfo   没有secondId时 则为0
        /* actionId:         action */
        /* eMove             1      */
        /* ePickUp           2      */
        /* ePutDown          3      */
        /* eToPlate          4      */
        /* eFromPlate        5      */
        /* eOpen             6      */
        /* eClose            7      */
        /* ePutIn            8      */
        /* eTakeOut          9      */
        bool isContiner(ObjectList& objlist,taskList& tasklist,unsigned int id);


        int LoadAction(ObjectList& objlist,taskList& tasklist,C_map& x_map);//把任务载入动作链

        int Score_vector(const vector<C_action_chain>& para_vector);//计算 传递的参数  分数 分数越高则执行起来越省力

        int mission_chain(ObjectList& objlist,taskList& tasklist);

        int door_event(ObjectList& objlist,taskList& tasklist);


        int LoadTaskReduce(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector);//tasklist转录到_reduce_para
        int MakePlan(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector);//算出最优走法
        int EstimateScore(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,const vector<C_action_chain>& para_vector,vector<C_action_chain>& target_para_vector);//对传入动作排序并选择评分最高者
        int CalculateScore(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector);//对传入动作评分

        int MissionTaskReduce(ObjectList& objlist,taskList& tasklist,vector<C_task_reduce>& task_reduce_para,vector<C_action_chain>& target_para_vector);//执行


        int cGive_analogy(ObjectList& objlist,taskList& tasklist,unsigned id);

        int cPutIn_analogy(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned continerId);

        int cPutOn_analogy(ObjectList& objlist,taskList& tasklist,unsigned id,unsigned bigId);

        int cPickUp_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id);

        int cPutDown_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id);

        int cTakeOut_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id,unsigned int continerId);
        //continerId为0时 需要保证id不在任何容器中 否则只保证inside(id,continer)不为真

        int cOpen_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id);

        int cClose_analogy(ObjectList& objlist,taskList& tasklist,unsigned int continerId);

        int cGoto_analogy(ObjectList& objlist,taskList& tasklist,unsigned int id);





        string getfirstword(string p1);
        void nat_to_ins(string &ntask, string ins[20][7]);
        string formatlize(string s[20][7]);
    private:
    protected:
        void Plan();
        void Fini();
    };

    TeamName::TeamName():
    Plug("TeamName")
    {

    }

}
void _home::TeamName::Plan()
{

    C_position::task_array.clear();
    C_position::action_chain.clear();
    C_position::do_action_chain.clear();
    C_position::task_array_door.clear();
    askInformation::box.clear();

    if(IS_RESERVE)
    {
        C_position::action_chain.reserve(RESERVE_NUM);
        C_position::task_array_door.reserve(RESERVE_NUM);
        askInformation::box.reserve(RESERVE_NUM);
        C_position::task_array.reserve(10);
    }

    //vector<C_task_reduce> task_reduce_vector;
    //vector<C_action_chain> action_chain_vector;


    string s=GetEnvDes();

    myplan::ObjectList m1;
    m1.EnvHandler(s);

    s=GetTaskDes();
    //s="go to worktable.";
    toLower(s);




    //nature n1;
    //n1.converToIns(s);
    //s=n1.result;



    //cout<<s<<endl;//debug delete

    myplan::taskList t1;
    t1.TaskHandler(s);





    funPriority(t1);
    sort(t1.task.begin(),t1.task.end());//task按照优先级升序排列

    answer_info(m1,t1);
    answer_task(m1,t1);
    supplyObjectList(m1,t1);

    resHandler_nInfo(m1,t1);
    resHandler_nnInfo(m1,t1);
    resHandler_nTask(m1,t1);

    answer_task(m1,t1);
////////////////////////////////////////////////////////////


    supplyTaskList(m1,t1);
    ChooseObj_ForAll(m1,t1);
    t1.BackUp();

    //debug
    //cout<<t1.cons_notInfo.size()<<endl;
    //cout<<t1.cons_notTask.size()<<endl;
    //cout<<getObj_id(m1,t1,6).keep_door<<endl;
    //cout<<getObj_id(m1,t1,10).hold_locked<<endl;
    //cout<<getObj_id(m1,t1,11).is_locked<<endl;
    //执行任务之前

    //LoadTaskReduce(m1,t1,task_reduce_vector,action_chain_vector);
    //MakePlan(m1,t1,task_reduce_vector,action_chain_vector);
    //MissionTaskReduce(m1,t1,task_reduce_vector,action_chain_vector);

    //C_map cm1;
    //LoadAction(m1,t1,cm1);

    m1.m_big_obj_number=0;

    for(vector<Object>::iterator it=m1.obj.begin();it!=m1.obj.end();it++)
    {
        if(it->size==2)
        {
            m1.m_big_obj_number++;
            m1.m_big_obj_id_vector.push_back(it->id);
        }
    }



    mission(m1,t1);
    mission_no_res(m1,t1);
    //cout<<AskLoc(21)<<endl;;

    //Move(2);
    //Open(2);
    //Move(3);
    //Open(3);


    askInformation::box.clear();
    C_position::action_chain.clear();
    C_position::do_action_chain.clear();
    C_position::task_array.clear();
    C_position::task_array_door.clear();
}
void _home::TeamName::Fini()
{
    std::cout<<"#(TeamName):Fini"<<std::endl;
}
#endif // TEAM_INCLUDED
