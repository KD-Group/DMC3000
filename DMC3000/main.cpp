#include <QApplication>
#include <QDebug>

#include "Windows.h"
#include "motion_3000.h"

class Motion {
private:
    unsigned short card;
    unsigned short home_dir[8];

public:
    enum AXIS {Vertical_Axis, Horizontal_Axis, UpDown_Axis};

public:
    Motion(): card(0) {
        puts("Created Motion Object...");

        set_home_dir(Vertical_Axis, 0);
        set_home_dir(Horizontal_Axis, 0);
        set_home_dir(UpDown_Axis, 1);
    }

    ~Motion() {
        board_close_e();
    }

    bool init() {
        board_init_e();

        get_card_info_list_e();

        set_alm_mode_e(this->card, this->Horizontal_Axis, 0, 0, 0);
        set_alm_mode_e(this->card, this->Vertical_Axis, 0, 0, 0);
        set_alm_mode_e(this->card, this->UpDown_Axis, 0, 0, 0);

        write_sevon_pin_e(this->card, this->Horizontal_Axis, 0);
        write_sevon_pin_e(this->card, this->Vertical_Axis, 0);
        write_sevon_pin_e(this->card, this->UpDown_Axis, 0);

        puts("Initialed Motion Card Success...");
        return true;
    }

    void set_home_dir(int axis, int dir) {
        this->home_dir[axis] = dir;
    }

    void home(int axis, int speed = 20000) {
        set_pulse_outmode_e(this->card, axis, 0);
        set_profile_e(this->card, axis, 500.0, speed, 0.1, 0.1, 500);
        set_homemode_e(this->card, axis, this -> home_dir[axis], 1 ,2, 1);
        home_move_e(this->card, axis);
    }

    void run(int axis, int length = 10000, int speed = 20000) {
        if (this->home_dir[axis]) length = -length;
        set_pulse_outmode_e(this->card, axis, 0);
        set_profile_e(this->card, axis, 500.0, speed, 0.1, 0.1, 500);
        set_s_profile_e(this->card, axis, 0, 0.0);
        pmove_e(this->card, axis, length, 0);
    }

    bool is_running(int axis) {
        return check_done(this->card, axis) == 0;
    }

    int position(int axis) {
        return get_position(this->card, axis);
    }

    void set_position(int axis, int position) {
        set_position_e(this->card, axis, position);
    }
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Motion x;
    qDebug() << x.init();

    printf("Init Motion Object Success");

    x.run(Motion::Vertical_Axis, 30000);
    x.run(Motion::Horizontal_Axis, 50000);

    while(x.is_running(Motion::Vertical_Axis)) { Sleep(100); }
    while(x.is_running(Motion::Horizontal_Axis)) { Sleep(100); }


    x.home(Motion::Vertical_Axis);
    x.home(Motion::Horizontal_Axis);

    return 0;
}
