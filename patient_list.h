#ifndef patient_list_h
#define patient_list_h
typedef struct mystruct {
	u8 name[30];
	u32 id ;
	u32 age;
	u8 gender[7];
	struct mystruct* Next;
}patient;

typedef struct clinc_res {
	u8 time[20];
	u32 id;	
}reservation;

void ViewPatient(patient * Start);
patient* AddNewPatient( patient * Start);
void EditPatient(patient * Start);
void ViewReserve(reservation * res_slot);
void CancelReserve(reservation * res_slot);
void ReserveSlot(reservation * res_slot);
#endif