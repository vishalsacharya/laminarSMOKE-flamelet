{
	if(tauEquation == true)
	{
		fvScalarMatrix tauEqn
		(
		    	fvm::div(phi, tau) 
		        == 
                        rho + 
		     	fvOptions(rho, tau)
		);

		// Solve
		tauEqn.relax();
		fvOptions.constrain(tauEqn);
		tauEqn.solve(mesh.solver("tau"));
	}
}
