#include "RandPacer.h"

void UpStateOfPacer::TurnLeft(Pacer* pacer)
{
	pacer->SetState(new LeftStateOfPacer());
}
void UpStateOfPacer::TurnRight(Pacer* pacer)
{
	pacer->SetState(new RightStateOfPacer());
}

void DownStateOfPacer::TurnLeft(Pacer* pacer)
{
	pacer->SetState(new RightStateOfPacer());
}
void DownStateOfPacer::TurnRight(Pacer* pacer)
{
	pacer->SetState(new LeftStateOfPacer());
}

void LeftStateOfPacer::TurnLeft(Pacer* pacer)
{
	pacer->SetState(new DownStateOfPacer());
}
void LeftStateOfPacer::TurnRight(Pacer* pacer)
{
	pacer->SetState(new UpStateOfPacer());
}

void RightStateOfPacer::TurnLeft(Pacer* pacer)
{
	pacer->SetState(new UpStateOfPacer());
}
void RightStateOfPacer::TurnRight(Pacer* pacer)
{
	pacer->SetState(new DownStateOfPacer());
}