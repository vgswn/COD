#include<bits/stdc++.h>
#include<unistd.h>
#include<string>
using namespace std;

typedef struct subj_struct {
    int elective;

    string s_sub[3];
    int teacher[3];
    string s_teacher[3];
} sec_subj;
sec_subj waste;


sec_subj v[7][5][4];
sec_subj sec_teacher[7][7];




int avail_teacher[400][5][4];
int hours_left[7][7];

string IntToString(int a) {
    ostringstream temp;
    temp << a;
    return temp.str();
}

int find_sec(int ts) {
    return (ts % 7);
}

int find_day(int ts) {
    int x = find_sec(ts);
    return (ts - x) / 28;
}

int find_slot(int ts) {
    int x = find_sec(ts);
    x = (ts - x) % 28;
    return x / 7;
}

int all_hrs_finished() {
    int flag = 1;
    for (int j = 0; j < 7; j++) {

        for (int i = 0; i < 7; i++) {
            if (hours_left[j][i] > 0) {

                flag = 0;
                break;
            }

        }


    }
    return flag;


}

void all_hrs_finished_print() {
    int flag = 1;
    for (int j = 0; j < 7; j++) {

        for (int i = 0; i < 7; i++) {
            cout << hours_left[j][i] << endl;

        }


    }



}

int free_or_not(int sec, int sub, int slot, int day) {
    if (sec_teacher[sec][sub].elective > 0) {
        int k = sec_teacher[sec][sub].elective;
        int flag = 0;
        for (int i = 0; i < k; i++) {
            if (avail_teacher[sec_teacher[sec][sub].teacher[i]][day][slot] != -1)
                flag = 1;
        }
        if (flag == 0)
            return 1;

    } else {
        if (avail_teacher[sec_teacher[sec][sub].teacher[0]][day][slot] == -1)
            return 1;
    }
    return 0;
}

int count_hr(int sub, int ts) {
    int c = 0;
    int slot = find_slot(ts);
    int day = find_day(ts);
    int sec = find_sec(ts);
    for (int i = 0; i < slot; i++) {
        if (v[sec][day][i].s_sub[0] == sec_teacher[sec][sub].s_sub[0]) {
            c++;
        }
    }
    return c;


}

int is_Safe(int sub, int ts) {
    int slot = find_slot(ts);
    int day = find_day(ts);
    int sec = find_sec(ts);

    if (hours_left[sec][sub] == 3) {

        int a = free_or_not(sec, sub, slot, day);

        return a;

    } else if (hours_left[sec][sub] == 2) {

        if (v[sec][day][find_slot(ts) - 1].s_sub[0] == sec_teacher[sec][sub].s_sub[0] && find_slot(ts) != 2) {

            return free_or_not(sec, sub, slot, day);
        } else if (count_hr(sub, ts) == 0) {
            return free_or_not(sec, sub, slot, day);
        }
    } else if (hours_left[sec][sub] == 1) {


        if (v[sec][day][find_slot(ts) - 1].s_sub[0] == sec_teacher[sec][sub].s_sub[0] && find_slot(ts) != 2) {
            if (count_hr(sub, ts) == 1) {
                return free_or_not(sec, sub, slot, day);
            }

        }
        if (count_hr(sub, ts) == 0) {

            return free_or_not(sec, sub, slot, day);
        }
    }

    return 0;
}

int algo(int ts) {
    if (all_hrs_finished()) {
        return 1;
    }

    int day = find_day(ts);
    int sec = find_sec(ts);
    int slot = find_slot(ts);
    for (int sub = 0; sub < 7; sub = sub + 1) {

        if (is_Safe(sub, ts)) {


            sec_subj p = sec_teacher[sec][sub];
            hours_left[find_sec(ts)][sub]--;
            v[sec][day][find_slot(ts)] = p;
            if (sec_teacher[sec][sub].elective > 0) {
                int k = sec_teacher[sec][sub].elective;
                int flag = 0;
                for (int i = 0; i < k; i++) {
                    avail_teacher[sec_teacher[sec][sub].teacher[i]][day][slot] = ts;

                }

            } else {
                avail_teacher[sec_teacher[sec][sub].teacher[0]][day][slot] = ts;
            }


            if (algo(ts + 1)) {

                return 1;
            }
            if (sec_teacher[sec][sub].elective > 0) {
                int k = sec_teacher[sec][sub].elective;
                int flag = 0;
                for (int i = 0; i < k; i++) {
                    avail_teacher[sec_teacher[sec][sub].teacher[i]][day][slot] = -1;

                }
            } else {
                avail_teacher[sec_teacher[sec][sub].teacher[0]][day][slot] = -1;
            }


            v[sec][day][find_slot(ts)] = waste;
            hours_left[find_sec(ts)][sub]++;

        }
    }

    return 0;
}

void print_timetable() {

    map<int, string>m_day;
    m_day[0] = "MONDAY";
    m_day[1] = "TUESDAY";
    m_day[2] = "WEDNESDAY";
    m_day[3] = "THURSDAY";
    m_day[4] = "FRIDAY";

    for (int sec = 0; sec < 7; sec++) {

        string tmp = "test" + IntToString(sec) + ".txt";

        char *q = const_cast<char*> (tmp.c_str());
        ofstream outfile(q);
        ofstream out;
        out.open(q);

        for (int day = 0; day < 5; day++) {
            out << m_day[day] << ";";


            for (int slot = 0; slot < 4; slot++) {

                if (v[sec][day][slot].elective == 0)
                    out << "$";
                else if (v[sec][day][slot].elective == -1) {
                    out << v[sec][day][slot].s_sub[0] + " " << v[sec][day][slot].s_teacher[0];
                } else if (v[sec][day][slot].elective > 0) {
                    int k = v[sec][day][slot].elective;

                    for (int q = 0; q < k; q++) {
                        out << v[sec][day][slot].s_sub[q] + " (" << v[sec][day][slot].s_teacher[q] << " )";
                        out << "!";
                    }

                }


                out << ";";


            }

            out << "\n";
            out << "\n";



        }
        out << "\n";
        out << "\n";
        out << "\n";
        out << "\n";


    }

}

int main() {
    int la = 200;
    string s;
    waste.s_sub[0] = "faltu";
    waste.elective = -2;
    for (int l = 0; l < 7; l++) {
        for (int m = 0; m < 7; m++) {
            sec_teacher[l][m].elective = -2;
            for (int z = 0; z < 3; z++) {
                stringstream ss;
                ss << (100 * l + 10 * m + z);
                s = ss.str();
                sec_teacher[l][m].s_sub[z] = "null" + s;
                sec_teacher[l][m].teacher[z] = la++;

                sec_teacher[l][m].s_teacher[z] = "  ";

            }
        }
    }
    ifstream inp_file;
    inp_file.open("inp.txt");
    int c;
    int sec;
    int no_subj;
    int j;
    for (int i = 0; i < 7; i++) {
        inp_file >> sec >> no_subj;

        j = 0;
        if (no_subj == 5) {
            sec_teacher[i][0].elective = 0;
            sec_teacher[i][6].elective = 0;
            j++;
            no_subj++;
        } else if (no_subj == 6) {
            sec_teacher[i][6].elective = 0;
        }
        for (; j < no_subj; j++) {
            inp_file >> c >> sec_teacher[i][j].elective;

            if (sec_teacher[i][j].elective == -1) {
                inp_file >> sec_teacher[i][j].s_sub[0];
                inp_file >> sec_teacher[i][j].teacher[0];
                inp_file >> sec_teacher[i][j].s_teacher[0];
            } else {
                for (int k = 0; k < sec_teacher[i][j].elective; k++) {
                    inp_file >> sec_teacher[i][j].s_sub[k];
                    inp_file >> sec_teacher[i][j].teacher[k];
                    inp_file >> sec_teacher[i][j].s_teacher[k];
                }
            }
        }

    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            hours_left[i][j] = 3;
        }
    }
    for (int i = 0; i < 7; i++) {
        hours_left[i][6] = 2;
    }
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++)
                avail_teacher[i][j][k] = -1;
        }
    }


    clock_t start = clock();
    int a = algo(0);
    clock_t stop = clock();


    print_timetable();




    //cout << "Time: " << (stop - start) / double(CLOCKS_PER_SEC) << endl;

    return 0;
}
