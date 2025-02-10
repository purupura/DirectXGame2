#pragma once

#include "Matrix4x4.h"
#include "Vector3.h"
#include "format"
#include "cassert"

#define _USE_MATH_DEFINES
#include "math.h"

void MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

void MakeScaleMatrix(const Vector3& scale);
void MakeTranslateMatrix(const Vector3& translate);

void MakeRotateXMatrix(float radian);

void MakeRotateYMatrix(float radian);

void MakeRotateZMatrix(float radian);


void Add(const Matrix4x4& mt1, const Matrix4x4& mt2);

void Subtract(const Matrix4x4& mt1, const Matrix4x4& mt2);

void Multiply(const Matrix4x4& mt1, const Matrix4x4& mt2);

void Inverse(const Matrix4x4& m);

void Transpose(const Matrix4x4& mt1);

void MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

void MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

void Cross(const Vector3& a, const Vector3& b);


//ビューポート変換行列
void MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

void Transform(const Vector3& vector, const Matrix4x4& matrix);

void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

void DrawSphere(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);