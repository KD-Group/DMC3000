#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "LTDMC.h"

static short board_init_e() {
    return dmc_board_init() > 0 ? 0 : 71;
}

static short board_reset_e() {
    return dmc_board_reset();
}

static short board_close_e() {
    return dmc_board_close();
}

static short get_card_info_list_e() {
    unsigned short card_num, card_list[8];
    unsigned long card_type_list[8];
    short ret = dmc_get_CardInfList(&card_num, card_type_list, card_list);

    if (card_num == 0 || ret != 0) return 71;
    return card_list[0];
}

static short set_alm_mode_e(unsigned short CardNo, unsigned short axis, unsigned short enable, unsigned short alm_logic, unsigned short alm_action) {
    return dmc_set_alm_mode(CardNo, axis, enable, alm_logic, alm_action);
}

static short write_sevon_pin_e(unsigned short CardNo,unsigned short axis,unsigned short on_off) {
    return dmc_write_sevon_pin(CardNo, axis, on_off);
}

static short set_pulse_outmode_e(unsigned short CardNo,unsigned short axis,unsigned short outmode) {
    return dmc_set_pulse_outmode(CardNo, axis, outmode);
}

static short set_profile_e(unsigned short CardNo,unsigned short axis,double Min_Vel,double Max_Vel,double Tacc,double Tdec,double Stop_Vel) {
    return dmc_set_profile(CardNo, axis, Min_Vel, Max_Vel, Tacc, Tdec, Stop_Vel);
}

static short set_s_profile_e(unsigned short CardNo,unsigned short axis,unsigned short s_mode,double s_para) {
    return dmc_set_s_profile(CardNo, axis, s_mode, s_para);
}

static short set_homemode_e(unsigned short CardNo,unsigned short axis,unsigned short home_dir,double vel_mode, unsigned short mode,unsigned short EZ_count) {
    return dmc_set_homemode(CardNo, axis, home_dir, vel_mode,  mode, EZ_count);
}

static short home_move_e(unsigned short CardNo,unsigned short axis) {
    return dmc_home_move(CardNo, axis);
}

static short pmove_e(unsigned short CardNo,unsigned short axis,long Dist,unsigned short posi_mode) {
    return dmc_pmove(CardNo, axis, Dist, posi_mode);
}

static short check_done(unsigned short CardNo,unsigned short axis) {
    return dmc_check_done(CardNo, axis);
}

static long get_position(unsigned short CardNo,unsigned short axis) {
    return dmc_get_position(CardNo, axis);
}

static short set_position_e(unsigned short CardNo,unsigned short axis,long current_position) {
    return dmc_set_position(CardNo, axis, current_position);
}

static short stop(unsigned short CardNo,unsigned short axis,unsigned short stop_mode) {
    return dmc_stop(CardNo, axis, stop_mode);
}

static short emg_stop_e(unsigned short CardNo) {
    return dmc_emg_stop(CardNo);
}

static short update_target_position_e(unsigned short CardNo,unsigned short axis,long dist,unsigned short posi_mode) {
    return dmc_update_target_position(CardNo, axis, dist, posi_mode);
}

static short reset_target_position_e(unsigned short CardNo,unsigned short axis,long dist,unsigned short posi_mode) {
    return dmc_reset_target_position(CardNo, axis, dist, posi_mode);
}
