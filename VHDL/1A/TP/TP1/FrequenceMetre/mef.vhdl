library IEEE;
    use IEEE.STD_LOGIC_1164.all;
    use IEEE.NUMERIC_STD.all;
    use IEEE.STD_LOGIC_UNSIGNED.all;

-- BLOCK: Mise en forme TTL --

entity m_e_form is
    port ( clk : in STD_LOGIC;
           TTL : in STD_LOGIC;
           TTL_mef : out STD_LOGIC);
end m_e_form;

architecture behavioral of m_e_form is
    type etat_type is (debut,mef,fin);
    signal etat : etat_type := debut;
    signal etat_suiv : etat_type;

begin

SYNC : process(clk)
begin
    if rising_edge(clk) then
        etat <= etat_suiv;
    end if;
end process;

COMB : process(etat,TTL)
begin
    case etat is
        when debut =>
            TTL_mef <='0';
            if TTL = '1' then
                etat_suiv <= mef;
            else
                etat_suiv <= debut;
            end if;
        when mef =>
            TTL_mef <= '1';
            etat_suiv <= fin;
        when fin =>
            TTL_mef <= '0';
            if TTL = '0' then
                etat_suiv <= debut;
            else
                etat_suiv <= fin;
            end if;
    end case;
end process;

end behavioral;
