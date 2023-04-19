<pre><div class="text_to_html">#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &lt;cstdio&gt;
#include &lt;cstring&gt;

using namespace std;

struct tyDir{
	string calle;
	int numero;
	string piso;
	string depto;	
};

struct tyAlumno{
	string nombre;
	string apellido;
	int dni;
	int legajo;
	char sexo;
	string fecha_nacimiento;
	int edad;
	string email;
	tyDir direccion;
};

struct tyCont{
	int qc;
	int qs;
	int qo;
};

void IngresoAlumno(tyAlumno &amp;alumno){
	cout&lt;&lt;&quot;Ingrese el nombre del alumno: &quot;;
	cin&gt;&gt;alumno.nombre;
	cout&lt;&lt;&quot;Ingrese el dni del alumno:&quot;;
	cin&gt;&gt;alumno.dni;
	cout&lt;&lt;&quot;Ingrese la calle del domicilio:&quot;;
	cin&gt;&gt;alumno.direccion.calle;
}

void contarPorUltimoDNI(int dni, tyCont &amp;contadores){
	cout&lt;&lt;dni&lt;&lt;endl;
}

int main(){

	tyAlumno alu;
	tyCont contar;
	//IniAlumno(alu);
	alu.edad=0;
	
	IngresoAlumno(alu);
	contarPorUltimoDNI(alu.dni, contar);
	cout&lt;&lt;alu.nombre&lt;&lt;endl;
	cout&lt;&lt;alu.dni&lt;&lt;endl;
	cout&lt;&lt;alu.direccion.calle;


}

</div></pre>