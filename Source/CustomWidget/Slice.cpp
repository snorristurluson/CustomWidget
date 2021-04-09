#include "Slice.h"

#define LOCTEXT_NAMESPACE "UMG"

void USlice::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	MySlice->SetBrush(&Brush);
	MySlice->SetAngle(Angle);
	MySlice->SetArcSize(ArcSize);
}

void USlice::ReleaseSlateResources(bool bReleaseChildren)
{
	MySlice.Reset();
}

#if WITH_EDITOR
const FText USlice::GetPaletteCategory()
{
	return LOCTEXT("CustomPaletteCategory", "My custom category!");
}
#endif

TSharedRef<SWidget> USlice::RebuildWidget()
{
	MySlice = SNew(SSlateSlice)
		.Brush(&Brush)
		.Angle(Angle)
		.ArcSize(ArcSize);
	return MySlice.ToSharedRef();
}
