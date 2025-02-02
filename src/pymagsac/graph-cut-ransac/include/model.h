// Copyright (C) 2019 Czech Technical University.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of Czech Technical University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Please contact the author of this library if you have any questions.
// Author: Daniel Barath (barath.daniel@sztaki.mta.hu)
#pragma once

#include <opencv2/core/core.hpp>
#include <vector>
#include <Eigen/Eigen>
#include "estimator.h"

template <typename T>
T CLAMP(const T& x, const T& min, const T& max) {
  return std::min(std::max(min, x), max);
}

namespace gcransac
{
	class Model
	{
	public:
		Eigen::MatrixXd descriptor; // The descriptor of the current model

		Model(const Eigen::MatrixXd &descriptor_) :
			descriptor(descriptor_)
		{

		}

		Model()
		{

		}
	};

	class FundamentalMatrix : public Model
	{
	public:
		FundamentalMatrix() :
			Model(Eigen::MatrixXd(3, 3))
		{}
		FundamentalMatrix(const FundamentalMatrix& other)
		{
			descriptor = other.descriptor;
		}
	};

	class EssentialMatrix : public Model
	{
	public:
		EssentialMatrix() :
			Model(Eigen::MatrixXd(3, 3))
		{}
		EssentialMatrix(const EssentialMatrix& other)
		{
			descriptor = other.descriptor;
		}
	};

	class Pose6D : public Model
	{
	public:
		Pose6D() :
			Model(Eigen::MatrixXd(3, 4))
		{}
		Pose6D(const Pose6D& other_)
		{
			descriptor = other_.descriptor;
		}
	};

	class Homography : public Model
	{
	public:
		Homography() :
			Model(Eigen::MatrixXd(3, 3))
		{}

		Homography(const Homography& other)
		{
			descriptor = other.descriptor;
		}
	};
}
