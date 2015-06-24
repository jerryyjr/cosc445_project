/*
Simulation for zebrafish segmentation
Copyright (C) 2013 Ahmet Ay, Jack Holland, Adriana Sperlea, Sebastian Sangervasi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
tests.cpp contains test functions for every mutant.
*/

#include "tests.hpp" // Function declarations

double test_wildtype_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = 29 < md.feat.period_post[IMH1] && md.feat.period_post[IMH1] < 31;
	md.conds_passed[SEC_POST][1] = md.feat.sync_score_post[IMH1] > 0.8;
	md.conds_passed[SEC_POST][2] = md.feat.peaktotrough_end[IMH1] >= 1.5 && md.feat.peaktotrough_mid[IMH1] >= 1.5 && (md.feat.peaktotrough_mid[IMH1] / md.feat.peaktotrough_end[IMH1]) <= 1.5;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]) + (md.conds_passed[SEC_POST][2] * md.cond_scores[SEC_POST][2]);
}

double test_her7_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = md.feat.sync_score_post[IMH1] < 0.75 || (0.1 < md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1] && md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1] < 0.4);
	md.conds_passed[SEC_POST][1] = 0.97 < (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) && (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) < 1.03;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]);
}

double test_her13_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = md.feat.sync_score_post[IMH1] > 0.8;
	md.conds_passed[SEC_POST][1] = 1.05 < (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) && (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) < 1.07;
	md.conds_passed[SEC_POST][2] = 0.85 < (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) && (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 1.15;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]) + (md.conds_passed[SEC_POST][2] * md.cond_scores[SEC_POST][2]);
}

double test_delta_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = md.feat.sync_score_post[IMH1] < 0.7;
	md.conds_passed[SEC_POST][1] = 1.07 < (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) && (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) < 1.20;
	md.conds_passed[SEC_POST][2] = 0.3 < (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) && (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.85;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]) + (md.conds_passed[SEC_POST][2] * md.cond_scores[SEC_POST][2]);
}

double test_her7her13_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = md.feat.sync_score_post[IMH1] > 0.8;
	md.conds_passed[SEC_POST][1] = 1.05 < (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) && (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) < 1.07;
	md.conds_passed[SEC_POST][2] = 0.85 < (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) && (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 1.15;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]) + (md.conds_passed[SEC_POST][2] * md.cond_scores[SEC_POST][2]);
}

double test_her1_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = 0.97 < (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) && (md.feat.period_post[IMH1] / wtfeat.period_post[IMH1]) < 1.03;
	md.conds_passed[SEC_POST][1] = 0.85 < (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) && (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 1.15; // originally between 0.95 and 1.05
	md.conds_passed[SEC_POST][2] = md.feat.sync_score_post[IMH1] > 0.8;
	return (md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0]) + (md.conds_passed[SEC_POST][1] * md.cond_scores[SEC_POST][1]) + (md.conds_passed[SEC_POST][2] * md.cond_scores[SEC_POST][2]);
}

double test_her7delta_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.2 || (md.feat.num_good_somites[IMH1] < 3) || ((md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.5 && md.feat.sync_score_post[IMH1] < 0.7);
	return md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0];
}

double test_her1delta_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.2 || (md.feat.num_good_somites[IMH1] < 3) || ((md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.5 && md.feat.sync_score_post[IMH1] < 0.7);
	return md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0];
}

double test_her7over_mutant_post (mutant_data& md, features& wtfeat) {
	return 0;
}

double test_her1over_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = (md.feat.amplitude_post[CMH7] / wtfeat.amplitude_post[CMH7]) < 0.2 || (md.feat.num_good_somites[CMH7] < 3);
	return md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0];
}

double test_deltaover_mutant_post (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_POST][0] = md.feat.sync_score_post[IMH1] < 0.7 || (0.1 < (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) && (md.feat.amplitude_post[IMH1] / wtfeat.amplitude_post[IMH1]) < 0.4);
	return md.conds_passed[SEC_POST][0] * md.cond_scores[SEC_POST][0];
}

double test_her1her7_mutant_post (mutant_data& md, features& wtfeat) {
    return 1;
}

double test_DAPT_mutant_post (mutant_data& md, features& wtfeat) {
    return 1;
}

double test_wildtype_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][1] = md.feat.sync_score_ant[IMH1] > 0.8;
	md.conds_passed[SEC_ANT][2] = 1.4 < (md.feat.period_ant[IMH1] / md.feat.period_post[IMH1]) && (md.feat.period_ant[IMH1] / md.feat.period_post[IMH1]) < 2.2;
	md.conds_passed[SEC_ANT][3] = 1.3 < (md.feat.amplitude_ant[IMDELTA] / md.feat.amplitude_post[IMDELTA]);
    md.conds_passed[SEC_ANT][4] = (1 - md.feat.comp_score_ant_mespa) / 2.0;
    md.conds_passed[SEC_ANT][5] = (1 - md.feat.comp_score_ant_mespb) / 2.0;
    //cerr << md.feat.comp_score_ant_mespa << " " << md.feat.comp_score_ant_mespb << endl;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]) + (md.conds_passed[SEC_ANT][4] * md.cond_scores[SEC_ANT][4]) + (md.conds_passed[SEC_ANT][5] * md.cond_scores[SEC_ANT][5]);;
}

double test_her7_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] < 0.85;
	md.conds_passed[SEC_ANT][1] = md.feat.sync_score_ant[IMH1] < 0.8; // less than 0.85 of wildtype would be ideal
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_her13_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] > 0.8;
	md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] > 0.85;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_delta_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] < 0.7;
	md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] < 0.85;
    md.conds_passed[SEC_ANT][2] = md.feat.amplitude_ant[IMMESPA] / wtfeat.amplitude_ant[IMMESPA] < 0.2;
    md.conds_passed[SEC_ANT][3] = md.feat.sync_score_ant[IMMESPB] < 0.7;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]);
}

double test_her7her13_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] > 0.8;
	md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] > 0.85;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_her1_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] > 0.8;
	return md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0];
}

double test_her7delta_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_post[IMH1] < 0.7;
	md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] < 0.4;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_her1delta_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] < 0.7;
	md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMH1] / wtfeat.amplitude_ant[IMH1] < 0.4;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_her7over_mutant_ant (mutant_data& md, features& wtfeat) {
    md.conds_passed[SEC_ANT][0] = (md.feat.amplitude_post_time[IMH1][0.5] / wtfeat.amplitude_post[IMH1]) < 0.2;
    md.conds_passed[SEC_ANT][1] = (md.feat.amplitude_post_time[IMH7][0.5] / wtfeat.amplitude_post[IMH7]) < 0.2;
    md.conds_passed[SEC_ANT][2] = (md.feat.amplitude_post_time[IMDELTA][0.5] / wtfeat.amplitude_post[IMDELTA]) < 0.2;
    md.conds_passed[SEC_ANT][3] = md.feat.amplitude_ant_time[IMH1][0.5] / wtfeat.amplitude_ant[IMH1];
    md.conds_passed[SEC_ANT][4] = md.feat.amplitude_ant_time[IMH7][0.5] / wtfeat.amplitude_ant[IMH7];
    md.conds_passed[SEC_ANT][5] = md.feat.amplitude_ant_time[IMMESPA][0.5] / wtfeat.amplitude_ant[IMMESPA];
    md.conds_passed[SEC_ANT][6] = md.feat.sync_time[IMDELTA][1] < 0.7;
    md.conds_passed[SEC_ANT][7] = md.feat.sync_time[IMMESPB][1.5] < 0.7;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]) + (md.conds_passed[SEC_ANT][4] * md.cond_scores[SEC_ANT][4]) + (md.conds_passed[SEC_ANT][5] * md.cond_scores[SEC_ANT][5]) + (md.conds_passed[SEC_ANT][6] * md.cond_scores[SEC_ANT][6]) + (md.conds_passed[SEC_ANT][7] * md.cond_scores[SEC_ANT][7]);
}

double test_her1over_mutant_ant (mutant_data& md, features& wtfeat) {
    md.conds_passed[SEC_ANT][0] = md.feat.amplitude_post_time[IMH1][0.5] / wtfeat.amplitude_post[IMH1] < 0.2;
    md.conds_passed[SEC_ANT][1] = md.feat.amplitude_post_time[IMH7][0.5] / wtfeat.amplitude_post[IMH7] < 0.2;
    md.conds_passed[SEC_ANT][2] = md.feat.amplitude_post_time[IMDELTA][0.5] / wtfeat.amplitude_post[IMDELTA] < 0.2;
    md.conds_passed[SEC_ANT][3] = md.feat.amplitude_ant_time[IMH1][0.5] / wtfeat.amplitude_ant[IMH1] < 0.2;
    md.conds_passed[SEC_ANT][4] = md.feat.amplitude_ant_time[IMH7][0.5] / wtfeat.amplitude_ant[IMH7] < 0.2;

	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]) + (md.conds_passed[SEC_ANT][4] * md.cond_scores[SEC_ANT][4]);
}

double test_deltaover_mutant_ant (mutant_data& md, features& wtfeat) {
	md.conds_passed[SEC_ANT][0] = md.feat.sync_score_ant[IMH1] < 0.7;
    md.conds_passed[SEC_ANT][1] = md.feat.sync_score_ant[IMH7] < 0.7;
	return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]);
}

double test_her1her7_mutant_ant (mutant_data& md, features& wtfeat) {
    md.conds_passed[SEC_ANT][0] = md.feat.amplitude_ant[IMMESPA] / wtfeat.amplitude_ant[IMMESPA] < 0.4;
    md.conds_passed[SEC_ANT][1] = md.feat.amplitude_ant[IMMESPB] / wtfeat.amplitude_ant[IMMESPB] < 0.4;
    md.conds_passed[SEC_ANT][2] = md.feat.sync_score_ant[IMMESPA] < 0.7;
    md.conds_passed[SEC_ANT][3] = md.feat.sync_score_ant[IMMESPB] < 0.7;
    return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]);
}

double test_DAPT_mutant_ant (mutant_data& md, features& wtfeat) {
    md.conds_passed[SEC_ANT][0] = md.feat.sync_time[IMH1][3] < 0.5;
    md.conds_passed[SEC_ANT][1] = md.feat.sync_time[IMH7][3] < 0.5;
    md.conds_passed[SEC_ANT][2] = md.feat.amplitude_ant_time[IMH1][3] / wtfeat.amplitude_ant[IMH1] < 0.85;
    md.conds_passed[SEC_ANT][3] = md.feat.amplitude_ant_time[IMH7][3] / wtfeat.amplitude_ant[IMH7] < 0.85;
    md.conds_passed[SEC_ANT][4] = md.feat.amplitude_ant[IMMESPA] / wtfeat.amplitude_ant[IMMESPA] < 0.2;
    md.conds_passed[SEC_ANT][5] = md.feat.sync_time[IMMESPB][3] < 0.7;
    return (md.conds_passed[SEC_ANT][0] * md.cond_scores[SEC_ANT][0]) + (md.conds_passed[SEC_ANT][1] * md.cond_scores[SEC_ANT][1]) + (md.conds_passed[SEC_ANT][2] * md.cond_scores[SEC_ANT][2]) + (md.conds_passed[SEC_ANT][3] * md.cond_scores[SEC_ANT][3]) + (md.conds_passed[SEC_ANT][4] * md.cond_scores[SEC_ANT][4]) + (md.conds_passed[SEC_ANT][5] * md.cond_scores[SEC_ANT][5]);
}

int test_wildtype_wave (pair<int, int> waves[], int num_waves, mutant_data& md, int wlength_post, int wlength_ant) {
	md.conds_passed[SEC_WAVE][0] = md.conds_passed[SEC_WAVE][0] && (2 <= num_waves && num_waves <= 3);
	
	// If there are not between 2 and 3 waves in the PSM the rest of the conditions default to false
	if (!md.conds_passed[SEC_WAVE][0]) {
		md.conds_passed[SEC_WAVE][1] = md.conds_passed[SEC_WAVE][1] && false;
		md.conds_passed[SEC_WAVE][2] = md.conds_passed[SEC_WAVE][2] && false;
		md.conds_passed[SEC_WAVE][3] = md.conds_passed[SEC_WAVE][3] && false;
	} else {
		md.conds_passed[SEC_WAVE][1] = md.conds_passed[SEC_WAVE][1] && (2 <= wlength_post && wlength_post <= 8);
		md.conds_passed[SEC_WAVE][2] = md.conds_passed[SEC_WAVE][2] && (2 <= wlength_ant && wlength_ant <= 8); 

		// Calculate traveling wave distance
		for (int wave = 1; wave < num_waves; wave++) {
			int dist = waves[wave].first - waves[wave - 1].second;
			md.conds_passed[SEC_WAVE][3] = md.conds_passed[SEC_WAVE][3] && (2 <= dist && dist <= 8);
		}
	}
	
	return (md.conds_passed[SEC_WAVE][0] * md.cond_scores[SEC_WAVE][0]) + (md.conds_passed[SEC_WAVE][1] * md.cond_scores[SEC_WAVE][1]) + (md.conds_passed[SEC_WAVE][2] * md.cond_scores[SEC_WAVE][2]) + (md.conds_passed[SEC_WAVE][3] * md.cond_scores[SEC_WAVE][3]);
}

int test_her1_wave (pair<int, int> waves[], int num_waves, mutant_data& md, int wlength_post, int wlength_ant) {
	md.conds_passed[SEC_WAVE][0] = (1 <= num_waves && num_waves <= 2);
	return md.conds_passed[SEC_WAVE][0] * md.cond_scores[SEC_WAVE][0];
}

