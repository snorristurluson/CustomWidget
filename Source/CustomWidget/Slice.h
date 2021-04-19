#pragma once

#include "CoreMinimal.h"


#include "SSlateSlice.h"
#include "Components/Widget.h"
#include "Slice.generated.h"

UCLASS()
class CUSTOMWIDGET_API USlice : public UWidget
{
	GENERATED_BODY()
public:
	virtual void SynchronizeProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Appearance")
	FSlateBrush Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Appearance")
	float ArcSize;

	UFUNCTION(BlueprintCallable, Category="Appearance")
    void SetAngle(float InAngle);

	UFUNCTION(BlueprintCallable, Category="Appearance")
    void SetArcSize(float InArcSize);

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
	
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	TSharedPtr<SSlateSlice> MySlice;
};
