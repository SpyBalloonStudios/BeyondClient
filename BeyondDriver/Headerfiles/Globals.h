#pragma once

namespace Globals {

	namespace Hook {
		const char* ModuleName = "\\SystemRoot\\System32\\drivers\\dxgkrnl.sys";
		LPCSTR RoutingName = "NtDxgkGetTrackedWorkloadStatistics";
	}
}